#include<gtk/gtk.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#include<pokergame.h>


GtkWidget *g_lbl_titulo;
GtkWidget *g_lbl_descripcion;
GtkWidget *g_ent_M;
GtkWidget *g_ent_N;
GtkWidget *g_lbl_cargando;
GtkWidget *g_lbl_cargandopts;
GtkWidget *g_lbl_teorico;
GtkWidget *g_lbl_estadistico;

GtkWidget *g_lbl_dobleparejas;
GtkWidget *g_lbl_fullhouse;
GtkWidget *g_lbl_poker;
GtkWidget *g_lbl_escalerareal;
GtkWidget *g_lbl_valorteorico;
GtkWidget *g_lbl_media;
GtkWidget *g_lbl_varianza;
GtkWidget *g_lbl_errormedia;
GtkWidget *g_lbl_dp_vt;
GtkWidget *g_lbl_dp_m;
GtkWidget *g_lbl_dp_v;
GtkWidget *g_lbl_dp_e;
GtkWidget *g_lbl_fh_vt;
GtkWidget *g_lbl_fh_m;
GtkWidget *g_lbl_fh_v;
GtkWidget *g_lbl_fh_e;
GtkWidget *g_lbl_p_vt;
GtkWidget *g_lbl_p_m;
GtkWidget *g_lbl_p_v;
GtkWidget *g_lbl_p_e;
GtkWidget *g_lbl_er_vt;
GtkWidget *g_lbl_er_m;
GtkWidget *g_lbl_er_v;
GtkWidget *g_lbl_er_e;

const gchar *ent_M_text;
const gchar *ent_N_text;


#define NPUNTOS 5


int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("glade/window_main.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);

    g_lbl_titulo = 		GTK_WIDGET(gtk_builder_get_object(builder, "lbl_titulo"));
    g_lbl_descripcion = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_descripcion"));
    g_ent_M = 			GTK_WIDGET(gtk_builder_get_object(builder, "ent_M"));
    g_ent_N = 			GTK_WIDGET(gtk_builder_get_object(builder, "ent_N"));
    g_lbl_cargando = 	GTK_WIDGET(gtk_builder_get_object(builder, "lbl_cargando"));
    g_lbl_cargandopts = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_cargandopts"));
    g_lbl_teorico = 	GTK_WIDGET(gtk_builder_get_object(builder, "lbl_teorico"));
    g_lbl_estadistico =	GTK_WIDGET(gtk_builder_get_object(builder, "lbl_estadistico"));
    
    g_lbl_dobleparejas =GTK_WIDGET(gtk_builder_get_object(builder, "lbl_dobleparejas"));
	g_lbl_fullhouse =	GTK_WIDGET(gtk_builder_get_object(builder, "lbl_fullhouse"));
	g_lbl_poker =		GTK_WIDGET(gtk_builder_get_object(builder, "lbl_poker"));
	g_lbl_escalerareal =GTK_WIDGET(gtk_builder_get_object(builder, "lbl_escalerareal"));
	g_lbl_valorteorico =GTK_WIDGET(gtk_builder_get_object(builder, "lbl_valorteorico"));
	g_lbl_media =		GTK_WIDGET(gtk_builder_get_object(builder, "lbl_media"));
	g_lbl_varianza  =	GTK_WIDGET(gtk_builder_get_object(builder, "lbl_varianza"));
	g_lbl_errormedia  =	GTK_WIDGET(gtk_builder_get_object(builder, "lbl_errormedia"));
	g_lbl_dp_vt  =		GTK_WIDGET(gtk_builder_get_object(builder, "lbl_dp_vt"));
	g_lbl_dp_m  =		GTK_WIDGET(gtk_builder_get_object(builder, "lbl_dp_m"));
	g_lbl_dp_v  =		GTK_WIDGET(gtk_builder_get_object(builder, "lbl_dp_v"));
	g_lbl_dp_e  =		GTK_WIDGET(gtk_builder_get_object(builder, "lbl_dp_e"));
	g_lbl_fh_vt  =		GTK_WIDGET(gtk_builder_get_object(builder, "lbl_fh_vt"));
	g_lbl_fh_m  =		GTK_WIDGET(gtk_builder_get_object(builder, "lbl_fh_m"));
	g_lbl_fh_v  =		GTK_WIDGET(gtk_builder_get_object(builder, "lbl_fh_v"));
	g_lbl_fh_e  =		GTK_WIDGET(gtk_builder_get_object(builder, "lbl_fh_e"));
	g_lbl_p_vt  =		GTK_WIDGET(gtk_builder_get_object(builder, "lbl_p_vt"));
	g_lbl_p_m  =		GTK_WIDGET(gtk_builder_get_object(builder, "lbl_p_m"));
	g_lbl_p_v  =		GTK_WIDGET(gtk_builder_get_object(builder, "lbl_p_v"));
	g_lbl_p_e  =		GTK_WIDGET(gtk_builder_get_object(builder, "lbl_p_e"));
	g_lbl_er_vt  =		GTK_WIDGET(gtk_builder_get_object(builder, "lbl_er_vt"));
	g_lbl_er_m  =		GTK_WIDGET(gtk_builder_get_object(builder, "lbl_er_m"));
	g_lbl_er_v  =		GTK_WIDGET(gtk_builder_get_object(builder, "lbl_er_v"));
	g_lbl_er_e  =		GTK_WIDGET(gtk_builder_get_object(builder, "lbl_er_e"));

    g_object_unref(builder);

    gtk_widget_show(window);
                 
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

void cargandopts(void *arg)
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
	pthread_create(&t_cargandopts, NULL,&cargandopts,NULL);
	

	//Aqui se hace la simulacion
	game();

	//Aqui se llaman todas las funciones de probabilidad


	//Mostrar informacion al usuario
	ent_M_text = gtk_entry_get_text (GTK_ENTRY (g_ent_M)); //obtiene un string con un numero de la interfaz
	ent_N_text = gtk_entry_get_text (GTK_ENTRY (g_ent_N));
	
	g_print ("ent_M_text contents: %s\n", ent_M_text);
	g_print ("ent_N_text contents: %s\n", ent_N_text);
	
	gtk_label_set_text(GTK_LABEL(g_lbl_dp_vt),ent_M_text);
	gtk_label_set_text(GTK_LABEL(g_lbl_dp_m),ent_N_text);
	
}


// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}








