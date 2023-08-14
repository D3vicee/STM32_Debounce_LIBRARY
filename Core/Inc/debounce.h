/*
 * debounce.h
 *
 *  Created on: Aug 14, 2023
 *      Author: D3vice
 */

#ifndef INC_DEBOUNCE_H_
#define INC_DEBOUNCE_H_
#endif /* INC_DEBOUNCE_H_ */

/*
 * BU DOSYA ANA PROGRAMIN İÇERİSİNE DAHİL EDİLMELİDİR. ARDINDAN VARIABLES KISMINDAKİ DEĞİŞKENLER ANA PROGRAMDA SORGULANARAK BUTON DURUMU ELDE EDİLMELİDİR.
 * THIS FILE MUST BE INCLUDED IN THE MAIN PROGRAM. THEN THE BUTTON STATUS MUST BE OBTAINED BY QUERYING THE VARIABLES IN THE VARIABLES SECTION IN THE MAIN PROGRAM.
 *
 * VARIABLES
 * but_state: Debounce fonksiyonuna gönderilen ilgili butonun durumunu tutan değişkendir. İçereceği değer 0 (Deactive) veya 1 (Active) olabilir.
 * but_count: Debounce fonksiyonuna gönderilen ilgili butona kaç kere basıldığı bilgisini tutan değişkendir (0-65536)(0x00-0xffff).
 *
 * FUNCTIONS
 * Debounce: 3 adet parametre alarak debounce işlemini gerçekleştiren fonksiyondur.
 * 			NOT: Systick veya 1ms aralıklarla sayan bir timer IRQ içerisinde çağırılmalıdır.
 * 			NOT: Kullanılmak istenen buton PULL_DOWN olarak ayarlanmalıdır.
 * 			Params;
 * 				BUT_GPIOx			: Kullanılmak istenen butonun bulumduğu port bilgisi
 * 				BUT_GPIO_Pin		: Kullanılmak istenen butonun pin bilgisi
 * 				BUT_debounce_time	: Debounce işlemi için kullanılacak olan gecikme. Sisteme göre denenerek bulunabilir (Recommend equals 5 or more than).
 */


extern uint16_t but_state, but_count;

void Debounce(GPIO_TypeDef* BUT_GPIOx, uint16_t BUT_GPIO_Pin, uint8_t BUT_debounce_time );
