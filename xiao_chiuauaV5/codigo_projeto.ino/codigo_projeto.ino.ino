#define EIDSP_QUANTIZE_FILTERBANK 0 // Desativa a qunatização do filtro usado pelo espectograma, que é usada para diminuir o tamanho do modelo
#define EI_CLASSIFIER_SLICES_PER_MODEL_WINDOW 4 // Define a janela de inferência (receberá 1000ms/4)

#include <PDM.h>
#include <XIAO_Comandos_gravados_na_XIAO_inferencing.h>

typedef struct { // Armazena o áudio capturado 
    signed short *buffers[2]; // Dois buffers de áudio
    unsigned char buf_select; // Alterna entre os buffers
    unsigned char buf_ready;  // Indica se um buffer tá pronto para inferência
    unsigned int buf_count;   // Quantidade de amostras já coletadas
    unsigned int n_samples;   // Qauntidade total de amostras necessárias
} inference_t;

static inference_t inference;
static bool record_ready = false;
static signed short *sampleBuffer; // Armazena os dados do microfone antes de mover para inference.buffer 
static bool debug_nn = false;      // Se true, imprime os vetores de características
static int print_results = -(EI_CLASSIFIER_SLICES_PER_MODEL_WINDOW); // controla quando imprimir os resultados. Só imprime após completar uma janela

void setup() {
  Serial.begin(115200);
  while (!Serial);


}

void loop() {
  // put your main code here, to run repeatedly:

}
