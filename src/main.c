/* licence-window.c
 *
 * Copyright 2020 Isaac Asley
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "buildtutorlia-config.h"

#include<gtk/gtk.h>
#include"sqlconn.h"

//Initilize all widgets that the will be called upon

GtkBuilder *builder;
GtkBuilder *sqlBuilder;
GtkWidget *window;
GtkWidget *NoteWindow;
GtkWidget *sqlWindow;
GtkWidget *dataOutput;

int sql;

int main(int argc, char **argv) {


  gtk_init (&argc, &argv);

  builder = gtk_builder_new_from_file ("/home/chaff/Projects/accounts/src/mainwindow.glade");//TODO create gresource xml and move out of main()
  sqlBuilder = gtk_builder_new_from_file ("/home/chaff/Projects/accounts/src/sqlbox.glade"); //TODO merge both glade files. This is for testing purposes only.

  window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));

  gtk_builder_connect_signals (builder, NULL);

  //sqlwindow set up

  sqlWindow = GTK_WIDGET (gtk_builder_get_object(sqlBuilder, "sqlwindow"));

  gtk_builder_connect_signals (sqlBuilder, NULL);


  //other windows and widget initialized
  NoteWindow = GTK_WIDGET (gtk_builder_get_object(builder, "text_window"));
  dataOutput = GTK_WIDGET(gtk_builder_get_object(sqlBuilder, "dataoutput"));

  sql = sqlcon ();

  printf("Version of libpq: %d\n", sql);

  gtk_widget_show_all(window);
  gtk_main();


  return 0;

}

//called when window is closed

void on_main_window_destroy()
{
  gtk_main_quit ();
}

//signal functions

void on_main_window_button1_clicked()
{
  gtk_widget_show_all(NoteWindow);
}

void on_main_window_button2_clicked()
{
  gtk_widget_show_all(sqlWindow);
}

void on_main_window_button3_clicked()
{
  g_print("this will be a jnl entry call");
}

void on_query_clicked()
{
  gtk_widget_show_all(dataOutput);
}


                                     
