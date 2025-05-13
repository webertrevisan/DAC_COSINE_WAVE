#include "freertos/FreeRTOS.h"            // Inclui definições básicas do FreeRTOS, como tarefas, prioridades, etc.
#include "freertos/task.h"                // Inclui funções específicas de tarefas do FreeRTOS (como criação e controle de tarefas).
#include "driver/dac_cosine.h"            // Inclui as funções e estruturas para usar a geração de ondas cosseno com o DAC.
#include "esp_log.h"                      // Inclui suporte para logging (mensagens de debug, erro, etc.)

static const char *TAG = "dac_cosine_example"; // Define uma TAG usada para identificar mensagens de log no terminal.

void app_main(void) // Função principal do programa, chamada automaticamente no ESP32 ao iniciar.
{
    dac_cosine_handle_t chan0_handle; // Declara um handle (ponteiro de controle) para o canal DAC de onda cossenoidal.

    dac_cosine_config_t cos0_cfg = {  // Declara e inicializa uma estrutura de configuração para a onda cossenoidal.
        .chan_id = DAC_CHAN_0,                  // Usa o canal DAC 0.
        .freq_hz = 1000,                        // Frequência da onda cosseno: 1000 Hz (1 kHz).
        .clk_src = DAC_COSINE_CLK_SRC_DEFAULT,  // Usa a fonte de clock padrão do DAC.
        .offset = 0,                            // Define o deslocamento de tensão (offset) como 0 V.
        .phase = DAC_COSINE_PHASE_0,            // Define a fase da onda como 0 graus.
        .atten = DAC_COSINE_ATTEN_DEFAULT,      // Atenuação padrão (ajuste de amplitude).
        .flags.force_set_freq = false,          // Não força a frequência caso haja limitação de clock.
    };

    ESP_LOGI(TAG, "Initializing DAC cosine wave generator..."); // Mostra no terminal uma mensagem informando que a inicialização do DAC começou.

    ESP_ERROR_CHECK(dac_cosine_new_channel(&cos0_cfg, &chan0_handle));  // Cria um novo canal DAC com a configuração definida e armazena o handle.
    ESP_ERROR_CHECK(dac_cosine_start(chan0_handle));                    // Inicia a geração da onda cosseno no canal criado.

    ESP_LOGI(TAG, "DAC cosine wave generator initialized."); // Mostra no terminal que a geração de onda cosseno foi inicializada com sucesso.
}
