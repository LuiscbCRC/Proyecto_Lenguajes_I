#include<gtk/gtk.h>
#include<stdio.h>
#include<stdlib.h>

GtkWidget *g_lbl_titulo;
GtkWidget *g_lbl_descripcion;
GtkWidget *g_lbl_M;
GtkWidget *g_lbl_N;
GtkWidget *g_lbl_cargando;
GtkWidget *g_lbl_cargandopts;
GtkWidget *g_lbl_teorico;
GtkWidget *g_lbl_estadistico;

GtkWidget *g_ent_entM;
GtkWidget *g_ent_entN;


#define NPUNTOS 5


int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window, *ent_M, *ent_N;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("glade/window_main.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);

    g_lbl_titulo = 		GTK_WIDGET(gtk_builder_get_object(builder, "lbl_titulo"));
    g_lbl_descripcion = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_descripcion"));
    g_lbl_M = 			GTK_WIDGET(gtk_builder_get_object(builder, "lbl_M"));
    g_lbl_N = 			GTK_WIDGET(gtk_builder_get_object(builder, "lbl_N"));
    g_lbl_cargando = 	GTK_WIDGET(gtk_builder_get_object(builder, "lbl_cargando"));
    g_lbl_cargandopts = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_cargandopts"));
    g_lbl_teorico = 	GTK_WIDGET(gtk_builder_get_object(builder, "lbl_teorico"));
    g_lbl_estadistico =	GTK_WIDGET(gtk_builder_get_object(builder, "lbl_estadistico"));
    
    g_ent_entM = 		GTK_WIDGET(gtk_builder_get_object(builder, "ent_entM"));
    g_ent_entN = 		GTK_WIDGET(gtk_builder_get_object(builder, "ent_entN"));

    g_object_unref(builder);

    gtk_widget_show(window);   
                 
    //delay(1000);
                 
    gtk_main();

    return 0;
}

char *repeatStr (char *str, size_t count) {
    if (count == 0) return NULL;
    char *ret = malloc (strlen (str) * count + count);
    if (ret == NULL) return NULL;
    strcpy (ret, str);
    while (--count > 0) {
        strcat (ret, " ");
        strcat (ret, str);
    }
    return ret;
}

void cargandopts()
{
	for(int i = 1; i <= 10 * NPUNTOS; i++)//cambiar a un while true cuando se esté cargando el proceso general y que el acabe este hilo cuando termine
	{	
		gtk_label_set_text(GTK_LABEL(g_lbl_cargandopts),(repeatStr(".",i % NPUNTOS)));
		usleep(500000);
	}
}

void on_btn_calcular_clicked(GtkButton *b)
{
	pthread_t t_cargandopts;
	pthread_create(&t_cargandopts, NULL,cargandopts,NULL);
	
	//const char *nombre;
	//nombre = gtk_entry_get_text (e);
	gtk_label_set_text (GTK_LABEL(g_lbl_teorico),gtk_entry_get_text (g_ent_entM));
	
	
	
	//gtk_editable_delete_text (GTK_EDITABLE(g_ent_entM), 0, -1);
	
}

/*void on_ent_M_changed(GtkEntry *e)
{
	char tmp[32];
	sprintf(tmp, "%s", gtk_entry_get_text(e));
	gtk_label_set_text(GTK_LABEL(g_lbl_teorico),(const gchar* ) tmp);
	
}*/


// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}








