//solar system model 
//plots elliptical course of earth around sun, students add other planets
//code base written by Dr. Mo, April 2017
//students: add your names here :D



#include <stdio.h>
#include <allegro5/allegro.h>
#include <iostream>
#include <math.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include<string>
using namespace std;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 700;

int main() {
	//distance calculation variables

	//FPS determines how fast the program runs
	float FPS;
	cout << "enter speed" << endl;
	cin >> FPS;

	//used later for calculating distance between planets
	double xdiff;
	double ydiff;
	double dist;

	//month timer- most recent minimum distance b/t earth and mars was May 30, 2016
	double year = 2016;
	string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October","November", "December" };
	int month = 5;
	int day = 0;

	//allegro variables
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *earth = NULL;
	ALLEGRO_BITMAP *sun = NULL;

	ALLEGRO_BITMAP *background = NULL;
	ALLEGRO_BITMAP *icon = NULL;
	bool redraw = true;
	int t = 0;


	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//LOOK HERE! Each planet needs an x,y position. Add two variables for each planet you want- one for its x position, another for y
	double earth_x;
	double earth_y;
	double mars_x;
	double mars_y;
	int sun_x = SCREEN_WIDTH / 2;
	int sun_y = SCREEN_HEIGHT / 2;

	int shortest_distance = 900000000;
	int day_of_shortest_distance = 0;
	int year_of_shortest_distance = 0;
	int month_of_shortest_distance = 0;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//variables for planets' orbits! You can find this information here:
	//https://nssdc.gsfc.nasa.gov/planetary/factsheet/
	double Earth_Semimajor_Axis = 149.6;
	double Mars_Semimajor_Axis = 227.9;
	double Earth_Eccentricity = .0167;
	double Mars_Eccentricity = .094;

	double Period_Ratio_Earth = 1;
	double Period_Ratio_Mars = .5317; //found by dividing orbital period of Earth by orbital period of Mars
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//initalize allegro libraries
	al_init();
	al_init_primitives_addon();
	al_init_image_addon();
	//set up timer and game screen
	timer = al_create_timer(1.0 / FPS);
	display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);

	//set game screen position, background, title, and icon
	al_set_window_position(display, 0, 0);
	al_set_window_title(display, "earth mars orbit sim");
	background = al_load_bitmap("space.jpg");
	icon = al_load_bitmap("mars.jpg");
	al_set_display_icon(display, icon);


	//set up queue and start timer
	al_set_target_bitmap(al_get_backbuffer(display));
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_start_timer(timer);


	//BEGIN GAME LOOP////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			t++;
			day++;

			//physics engine!



			//parametric equations for Earth's elliptical orbit

			earth_x = Earth_Semimajor_Axis*(cos((t*3.14*Period_Ratio_Earth) / 180 - Earth_Eccentricity)) + SCREEN_WIDTH / 2;

			earth_y = Earth_Semimajor_Axis*(sqrt((1 - Earth_Eccentricity)*(1 - Earth_Eccentricity))*sin((t*3.14*Period_Ratio_Earth) / 180)) + SCREEN_HEIGHT / 2;

			//parametric equations for Mars orbit go here

			mars_x = Mars_Semimajor_Axis*(cos((t*3.14*Period_Ratio_Mars) / 180 - Mars_Eccentricity)) + SCREEN_WIDTH / 2;

			mars_y = Mars_Semimajor_Axis*(sqrt((1 - Mars_Eccentricity)*(1 - Mars_Eccentricity))*sin((t*3.14*Period_Ratio_Mars) / 180)) + SCREEN_HEIGHT / 2;

			//time calculation
			//2pi = 365 days
			//cout << "days: " << t << endl;

			//update and print out date to console
			if (t % 30 == 0) {
				//cout << months[month] << ", " << year << endl;
				month++;
			}
			if (month == 11) {
				day = 0;
				month = 0;
				year++;
				shortest_distance = 90000;
			}


			//distance calulation 
			xdiff = (Earth_Semimajor_Axis*(cos((t*3.14*Period_Ratio_Earth) / 180 - Earth_Eccentricity)) + SCREEN_WIDTH / 2) - (Mars_Semimajor_Axis*(cos((t*3.14*.5317) / 180 - Mars_Eccentricity)) + SCREEN_WIDTH / 2);
			ydiff = (Earth_Semimajor_Axis*(sqrt((1 - Earth_Eccentricity)*(1 - Earth_Eccentricity))*sin((t*3.14) / 180)) + SCREEN_HEIGHT / 2) - (Mars_Semimajor_Axis*(sqrt((1 - Mars_Eccentricity)*(1 - Mars_Eccentricity))*sin((t*3.14*Period_Ratio_Mars) / 180)) + SCREEN_HEIGHT / 2);
			dist = sqrt(ydiff*ydiff + xdiff*xdiff);
			//cout << "distance between planets: " << dist << endl;
			if (dist < shortest_distance) {
				shortest_distance = dist;
				day_of_shortest_distance = day;
				year_of_shortest_distance = year;
				month_of_shortest_distance = month;
				//cout << "shortest distance:" << shortest_distance << ", day of:" << day_of_shortest_distance << ", year of:" << year_of_shortest_distance << endl;
				cout << "distance of: " << shortest_distance << " at " << month_of_shortest_distance << "/" << day_of_shortest_distance << "/" << year_of_shortest_distance << endl;
			}
			
			redraw = true;
		}

		//close window if x is clicked
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		//RENDER SECTION/////////////////////////////////////////////////////////////////////
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));
			if (background != NULL)
				al_draw_bitmap(background, 0, 0, NULL);

			//draw sun
			al_draw_filled_circle(sun_x, sun_y, 10, al_map_rgb(250, 250, 50));
			//draw earth
			al_draw_filled_circle(earth_x, earth_y, 5, al_map_rgb(50, 50, 200));
			//other planets go here
			al_draw_filled_circle(mars_x, mars_y, 5, al_map_rgb(200, 0, 0));


			al_flip_display();
		}//end of render section
	}//end of game loop

	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}//end of main