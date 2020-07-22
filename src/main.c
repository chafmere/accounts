
#include "buildtutorlia-config.h"

#include<gtk/gtk.h>

//Initilize all widgets that the will be called upon

GtkBuilder *builder;
GtkBuilder *sqlBuilder;
GtkWidget *window;
GtkWidget *NoteWindow;
GtkWidget *sqlWindow;
GtkWidget *dataOutput;

int main(int argc, char **argv) {


  gtk_init (&argc, &argv);

  builder = gtk_builder_new_from_file ("/home/chaff/Projects/buildtutorlia/src/mainwindow.glade");
  sqlBuilder = gtk_builder_new_from_file ("/home/chaff/Projects/buildtutorlia/src/sqlbox.glade"); //TODO merger both glade files. This is for testing purposes only.

  window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));

  gtk_builder_connect_signals (builder, NULL);

  //sqlwindow set up

  sqlWindow = GTK_WIDGET (gtk_builder_get_object(sqlBuilder, "sqlwindow"));

  gtk_builder_connect_signals (sqlBuilder, NULL);


  //other windows and widget initialized
  NoteWindow = GTK_WIDGET (gtk_builder_get_object(builder, "text_window"));
  dataOutput = GTK_WIDGET(gtk_builder_get_object(sqlBuilder, "dataoutput"));


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



