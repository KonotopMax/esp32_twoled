#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

static const char *TAG = "LED_APP";

// Определяем пины для светодиодов
#define LED1 GPIO_NUM_4   // Первый светодиод
#define LED2 GPIO_NUM_2   // Второй светодиод - меняем на GPIO2

void app_main(void)
{
    // Настройка пинов
    gpio_reset_pin(LED1);
    gpio_reset_pin(LED2);
    gpio_set_direction(LED1, GPIO_MODE_OUTPUT);
    gpio_set_direction(LED2, GPIO_MODE_OUTPUT);
    
    ESP_LOGI(TAG, "Программа запущена!"); //Программа запущена!
    ESP_LOGI(TAG, "Светодиоды должны мигать поочередно");
    ESP_LOGI(TAG, "Подключение:");
    ESP_LOGI(TAG, "- GPIO4 -> Резистор 220Ом -> АНОД первого светодиода -> КАТОД -> GND");
    ESP_LOGI(TAG, "- GPIO2 -> Резистор 220Ом -> АНОД второго светодиода -> КАТОД -> GND");
    
    while(1) {
        // Включаем первый, выключаем второй
        gpio_set_level(LED1, 1);
        gpio_set_level(LED2, 0);
        ESP_LOGI(TAG, "Светодиод 1 включен, Светодиод 2 выключен");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        
        // Выключаем первый, включаем второй
        gpio_set_level(LED1, 0);
        gpio_set_level(LED2, 1);
        ESP_LOGI(TAG, "Светодиод 1 выключен, Светодиод 2 включен");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}