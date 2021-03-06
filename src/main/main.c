#include<gtk/gtk.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<pokergame.h>

#define NPUNTOS 5

GtkWidget *g_lbl_titulo, *g_lbl_descripcion, *g_ent_M, *g_ent_N, *g_lbl_cargando, *g_lbl_cargandopts, *g_lbl_teorico, *g_lbl_estadistico;
GtkWidget *g_lbl_dobleparejas, *g_lbl_fullhouse, *g_lbl_poker, *g_lbl_escalerareal, *g_lbl_valorteorico, *g_lbl_media, *g_lbl_varianza, *g_lbl_errormedia;
GtkWidget *g_lbl_dp_vt, *g_lbl_dp_m, *g_lbl_dp_v, *g_lbl_dp_e, *g_lbl_fh_vt, *g_lbl_fh_m, *g_lbl_fh_v, *g_lbl_fh_e, *g_lbl_p_vt, *g_lbl_p_m, *g_lbl_p_v, *g_lbl_p_e, *g_lbl_er_vt, *g_lbl_er_m, *g_lbl_er_v, *g_lbl_er_e;

int * cantidadJuegos;

const gchar *ent_M_text;
const gchar *ent_N_text;

const gchar *porcentaje;

const gchar *doblePar_text1;
const gchar *doblePar_text2;
const gchar *doblePar_text3;
const gchar *doblePar_text4;

const gchar *fullHouse_text1;
const gchar *fullHouse_text2;
const gchar *fullHouse_text3;
const gchar *fullHouse_text4;

const gchar *poker_text1;
const gchar *poker_text2;
const gchar *poker_text3;
const gchar *poker_text4;

const gchar *escaleraReal_text1;
const gchar *escaleraReal_text2;
const gchar *escaleraReal_text3;
const gchar *escaleraReal_text4;

int main(int argc, char *argv[])
{
	printf("\n\n\n\n========[Poker Simulacion]========\n\n");
	int simulations = 0;
    GtkBuilder      *builder; 
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("../glade/window_main.glade");

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
/*
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

static void *cargandopts(void *arg)
{
	for(int i = 1; i <= 10 * NPUNTOS; i++)//cambiar a un while true cuando se est?? cargando el proceso general y que el acabe este hilo cuando termine
	{	
		gtk_label_set_text(GTK_LABEL(g_lbl_cargandopts),(repeatStr(".",i % NPUNTOS)));
		sleep(1);
	}
}
*/

void on_btn_calcular_clicked(GtkButton *b)
{
	//pthread_t t_cargandopts;
	//pthread_create(&t_cargandopts, NULL,cargandopts,NULL);

	//Obtener valores del usuario
	ent_M_text = gtk_entry_get_text (GTK_ENTRY (g_ent_M));
	ent_N_text = gtk_entry_get_text (GTK_ENTRY (g_ent_N));
	const int M_num = atoi(ent_M_text);
	int N_num = atoi(ent_N_text);
	
	static double listProbabilityDoublePar[500000];
	static double listProbabilityFullHouse[500000];
	static double listProbabilityPoker[500000];
	static double listProbabilityRealStraight[500000];

	//Aqui se hace la simulacion
	
	for(int simulations = 0; simulations < M_num; simulations++){

		porcentaje = g_strdup_printf(" %d", (100 * simulations/(N_num)));

		gtk_label_set_text(GTK_LABEL(g_lbl_cargandopts),porcentaje);

		cantidadJuegos = game(N_num);
		listProbabilityDoublePar[simulations] = getProbability(*(cantidadJuegos +0) , N_num);
		listProbabilityFullHouse[simulations] = getProbability(*(cantidadJuegos +1) , N_num);
		listProbabilityPoker[simulations] = getProbability(*(cantidadJuegos +2) , N_num);
		listProbabilityRealStraight[simulations] = getProbability(*(cantidadJuegos +3) , N_num);
	}

	/*
	
	printf("Lista de probabilidades para Doble Par: [");
	for(int simulations = 0; simulations < M_num; simulations++){
		printf (" %f ", *(listProbabilityDoublePar +simulations));
	}
	printf("]\n");

	printf("Lista de probabilidades para Full House: [");
	for(int simulations = 0; simulations < M_num; simulations++){
		printf (" %f ", *(listProbabilityFullHouse +simulations));
	}
	printf("]\n");

	printf("%f", (binomialcoef(4,3)*binomialcoef(4,2)*binomialcoef(13,2)));

	printf("Lista de probabilidades para Poker: [");
	for(int simulations = 0; simulations < M_num; simulations++){
		printf (" %f ", *(listProbabilityPoker +simulations));
	}
	printf("]\n");

	printf("Lista de probabilidades para Escalera Real: [");
	for(int simulations = 0; simulations < M_num; simulations++){
		printf (" %f ", *(listProbabilityRealStraight +simulations));
	}
	printf("]\n");
	
	*/
	
	//Esto es para calcular la media de los resltados de probabilidad empirico
	double doubleParAverage = mediaEmpirica(listProbabilityDoublePar, M_num);
	double fullHouseAverage = mediaEmpirica(listProbabilityFullHouse, M_num);
	double pokerAverage = mediaEmpirica(listProbabilityPoker, M_num);
	double realStraightAverage = mediaEmpirica(listProbabilityRealStraight, M_num);
	
	//Aqui se calcula desviaci??n estandar
	double doubleParStandarDeviation = varianciaEmpirica(listProbabilityDoublePar, M_num, doubleParAverage);
	double fullHouseStandarDeviation = varianciaEmpirica(listProbabilityFullHouse, M_num, fullHouseAverage);
	double pokerStandarDeviation = varianciaEmpirica(listProbabilityPoker, M_num, pokerAverage);
	double realStraightStandarDeviation = varianciaEmpirica(listProbabilityRealStraight, M_num, realStraightAverage);
	
	//En esta parte se calcula el valor teorico
	double doubleParTheoric = ((binomialcoef(13,2)*binomialcoef(4,2)*binomialcoef(4,2)*binomialcoef(11,1)*binomialcoef(4,1))/ (double) ALLCARDS)*100.0;
	double fullHouseTheoric = ((binomialcoef(13,1)*binomialcoef(12,1)*binomialcoef(4,3)*binomialcoef(4,2))/ (double) ALLCARDS)*100.0;
	double pokerTheoric = ((binomialcoef(13,1)* binomialcoef(4,4)*binomialcoef(12,1)*binomialcoef(4,1))/ (double) ALLCARDS)*100.0;
	double realStraightTheoric = ((binomialcoef(4,1))/ (double) ALLCARDS)*100.0;
	
	//Aqui se calcula el valor del error entre el valor teorico y el empirico
	double doubleParError = calculateError(doubleParTheoric, doubleParAverage);
	double fullHouseError = calculateError(fullHouseTheoric, fullHouseAverage);
	double pokerError = calculateError(pokerTheoric, pokerAverage);
	double realStraightError = calculateError(realStraightTheoric, realStraightAverage);
	
	doblePar_text1 = g_strdup_printf("%6.5f", doubleParTheoric);
	doblePar_text2 = g_strdup_printf("%6.5f", doubleParAverage);
	doblePar_text3 = g_strdup_printf("%6.5f", doubleParStandarDeviation);
	doblePar_text4 = g_strdup_printf("%6.5f", doubleParError);

	fullHouse_text1 = g_strdup_printf("%6.5f", fullHouseTheoric);
	fullHouse_text2 = g_strdup_printf("%6.5f", fullHouseAverage);
	fullHouse_text3 = g_strdup_printf("%6.6f", fullHouseStandarDeviation);
	fullHouse_text4 = g_strdup_printf("%6.5f", fullHouseError);

	poker_text1 = g_strdup_printf("%6.5f", pokerTheoric);
	poker_text2 = g_strdup_printf("%6.5f", pokerAverage);
	poker_text3 = g_strdup_printf("%6.7f", pokerStandarDeviation);
	poker_text4 = g_strdup_printf("%6.5f", pokerError);

	escaleraReal_text1 = g_strdup_printf("%6.5f", realStraightTheoric);
	escaleraReal_text2 = g_strdup_printf("%6.5f", realStraightAverage);
	escaleraReal_text3 = g_strdup_printf("%6.7f", realStraightStandarDeviation);
	escaleraReal_text4 = g_strdup_printf("%6.5f", realStraightError);

	gtk_label_set_text(GTK_LABEL(g_lbl_dp_vt),doblePar_text1);
	gtk_label_set_text(GTK_LABEL(g_lbl_dp_m),doblePar_text2);
	gtk_label_set_text(GTK_LABEL(g_lbl_dp_v),doblePar_text3);
	gtk_label_set_text(GTK_LABEL(g_lbl_dp_e),doblePar_text4);

	gtk_label_set_text(GTK_LABEL(g_lbl_fh_vt),fullHouse_text1);
	gtk_label_set_text(GTK_LABEL(g_lbl_fh_m),fullHouse_text2);
	gtk_label_set_text(GTK_LABEL(g_lbl_fh_v),fullHouse_text3);
	gtk_label_set_text(GTK_LABEL(g_lbl_fh_e),fullHouse_text4);

	gtk_label_set_text(GTK_LABEL(g_lbl_p_vt),poker_text1);
	gtk_label_set_text(GTK_LABEL(g_lbl_p_m),poker_text2);
	gtk_label_set_text(GTK_LABEL(g_lbl_p_v),poker_text3);
	gtk_label_set_text(GTK_LABEL(g_lbl_p_e),poker_text4);

	gtk_label_set_text(GTK_LABEL(g_lbl_er_vt),escaleraReal_text1);
	gtk_label_set_text(GTK_LABEL(g_lbl_er_m),escaleraReal_text2);
	gtk_label_set_text(GTK_LABEL(g_lbl_er_v),escaleraReal_text3);
	gtk_label_set_text(GTK_LABEL(g_lbl_er_e),escaleraReal_text4);
	
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}








