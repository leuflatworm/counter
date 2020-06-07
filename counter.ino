#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFi.h>
#include <WiFiUdp.h>

#include "M5Atom.h"
#include <EEPROM.h>

const char *wifi_ssid = "";
const char *wifi_pass = "";


uint8_t counter = 0; //1の位カウンター
uint8_t counter10 = 0; //10の位カウンター


const CRGB COLOR[4] = { //色設定
  0xf00000,
  0x00f000,
  0x0000f0,
  0x707070
}; 

void setup() {
    M5.begin(true, false, true);
    delay(50);
    M5.dis.clear();

    WiFi.begin(wifi_ssid, wifi_pass);
    int w = 0;
    while (WiFi.status() != WL_CONNECTED ) {
      M5.dis.drawpix(w, COLOR[0]);
      delay(1000);

      w++;
      if (w>24){
        break;
      }
    }

    
    for (int i=0; i<25; i++) { //中央3列の表示をリセット
      M5.dis.drawpix(i, 0x000000);
    }

    
    //最初に0を表示する
    M5.dis.drawpix(1, COLOR[2]);
    M5.dis.drawpix(2, COLOR[2]);
    M5.dis.drawpix(3, COLOR[2]);
    M5.dis.drawpix(6, COLOR[2]);
    M5.dis.drawpix(8, COLOR[2]);
    M5.dis.drawpix(11, COLOR[2]);
    M5.dis.drawpix(13, COLOR[2]);
    M5.dis.drawpix(16, COLOR[2]);
    M5.dis.drawpix(18, COLOR[2]);
    M5.dis.drawpix(21, COLOR[2]);
    M5.dis.drawpix(22, COLOR[2]);
    M5.dis.drawpix(23, COLOR[2]);
    M5.update();
    
}

void loop() {
    // ボタン(画面)をクリックすると、LEDを順番に点灯していく。一週したら色を変える。
    if (M5.Btn.wasPressed()) {
        counter++;
        if (10 <= counter) { //10数える毎に左右の10の位カウンターを増やして1の位カウンターを0にする
            counter = 0;

            if (counter10 < 5) { //1〜5までは左側
                M5.dis.drawpix(counter10 * 5, COLOR[0]);
                counter10++;
            } else if (counter10 < 10) { //5〜10までは右側
                M5.dis.drawpix((counter10 -5) * 5 + 4, COLOR[0]);
                counter10++;
            } else { //全て埋まったらリセット
                for (int i=0; i<25; i++) {
                    M5.dis.drawpix(i, 0x000000);
                }
                counter10 = 0;
            }
            
        }

        for (int i=0; i<5; i++) { //中央3列の表示をリセット
          for (int j=1; j<4; j++) {
            M5.dis.drawpix(i*5 + j, 0x000000); 
          }
        }

        if(counter == 0){ //0の表示
            M5.dis.drawpix(1, COLOR[2]);
            M5.dis.drawpix(2, COLOR[2]);
            M5.dis.drawpix(3, COLOR[2]);
            M5.dis.drawpix(6, COLOR[2]);
            M5.dis.drawpix(8, COLOR[2]);
            M5.dis.drawpix(11, COLOR[2]);
            M5.dis.drawpix(13, COLOR[2]);
            M5.dis.drawpix(16, COLOR[2]); 
            M5.dis.drawpix(18, COLOR[2]);
            M5.dis.drawpix(21, COLOR[2]);
            M5.dis.drawpix(22, COLOR[2]);
            M5.dis.drawpix(23, COLOR[2]);
        }else if(counter == 1){ //1の表示
            M5.dis.drawpix(1, COLOR[2]);
            M5.dis.drawpix(2, COLOR[2]);
            M5.dis.drawpix(7, COLOR[2]);
            M5.dis.drawpix(12, COLOR[2]);
            M5.dis.drawpix(17, COLOR[2]);
            M5.dis.drawpix(21, COLOR[2]);
            M5.dis.drawpix(22, COLOR[2]);
            M5.dis.drawpix(23, COLOR[2]);
        }else if(counter == 2){ //2の表示
            M5.dis.drawpix(1, COLOR[2]);
            M5.dis.drawpix(2, COLOR[2]);
            M5.dis.drawpix(3, COLOR[2]);
            M5.dis.drawpix(8, COLOR[2]);
            M5.dis.drawpix(11, COLOR[2]);
            M5.dis.drawpix(12, COLOR[2]);
            M5.dis.drawpix(13, COLOR[2]);
            M5.dis.drawpix(16, COLOR[2]);
            M5.dis.drawpix(21, COLOR[2]);
            M5.dis.drawpix(22, COLOR[2]);
            M5.dis.drawpix(23, COLOR[2]);
        }else if(counter == 3){ //3の表示
            M5.dis.drawpix(1, COLOR[2]);
            M5.dis.drawpix(2, COLOR[2]);
            M5.dis.drawpix(3, COLOR[2]);
            M5.dis.drawpix(8, COLOR[2]);
            M5.dis.drawpix(11, COLOR[2]);
            M5.dis.drawpix(12, COLOR[2]);
            M5.dis.drawpix(13, COLOR[2]);
            M5.dis.drawpix(18, COLOR[2]);
            M5.dis.drawpix(21, COLOR[2]);
            M5.dis.drawpix(22, COLOR[2]);
            M5.dis.drawpix(23, COLOR[2]);
        }else if(counter == 4){ //4の表示
            M5.dis.drawpix(1, COLOR[2]);
            M5.dis.drawpix(3, COLOR[2]);
            M5.dis.drawpix(6, COLOR[2]);
            M5.dis.drawpix(8, COLOR[2]);
            M5.dis.drawpix(11, COLOR[2]);
            M5.dis.drawpix(12, COLOR[2]);
            M5.dis.drawpix(13, COLOR[2]);
            M5.dis.drawpix(18, COLOR[2]);
            M5.dis.drawpix(23, COLOR[2]);
        }else if(counter == 5){ //5の表示
            M5.dis.drawpix(1, COLOR[2]);
            M5.dis.drawpix(2, COLOR[2]);
            M5.dis.drawpix(3, COLOR[2]);
            M5.dis.drawpix(6, COLOR[2]);
            M5.dis.drawpix(11, COLOR[2]);
            M5.dis.drawpix(12, COLOR[2]);
            M5.dis.drawpix(13, COLOR[2]);
            M5.dis.drawpix(18, COLOR[2]);
            M5.dis.drawpix(21, COLOR[2]);
            M5.dis.drawpix(22, COLOR[2]);
            M5.dis.drawpix(23, COLOR[2]);
        }else if(counter == 6){ //6の表示
            M5.dis.drawpix(1, COLOR[2]);
            M5.dis.drawpix(2, COLOR[2]);
            M5.dis.drawpix(3, COLOR[2]);
            M5.dis.drawpix(6, COLOR[2]);
            M5.dis.drawpix(11, COLOR[2]);
            M5.dis.drawpix(12, COLOR[2]);
            M5.dis.drawpix(13, COLOR[2]);
            M5.dis.drawpix(16, COLOR[2]); 
            M5.dis.drawpix(18, COLOR[2]);
            M5.dis.drawpix(21, COLOR[2]);
            M5.dis.drawpix(22, COLOR[2]);
            M5.dis.drawpix(23, COLOR[2]);
        }else if(counter == 7){ //7の表示
            M5.dis.drawpix(1, COLOR[2]);
            M5.dis.drawpix(2, COLOR[2]);
            M5.dis.drawpix(3, COLOR[2]);
            M5.dis.drawpix(8, COLOR[2]);
            M5.dis.drawpix(13, COLOR[2]);
            M5.dis.drawpix(18, COLOR[2]);
            M5.dis.drawpix(23, COLOR[2]);
        }else if(counter == 8){ //8の表示
            M5.dis.drawpix(1, COLOR[2]);
            M5.dis.drawpix(2, COLOR[2]);
            M5.dis.drawpix(3, COLOR[2]);
            M5.dis.drawpix(6, COLOR[2]);
            M5.dis.drawpix(8, COLOR[2]);
            M5.dis.drawpix(11, COLOR[2]);
            M5.dis.drawpix(12, COLOR[2]);
            M5.dis.drawpix(13, COLOR[2]);
            M5.dis.drawpix(16, COLOR[2]); 
            M5.dis.drawpix(18, COLOR[2]);
            M5.dis.drawpix(21, COLOR[2]);
            M5.dis.drawpix(22, COLOR[2]);
            M5.dis.drawpix(23, COLOR[2]);
        }else if(counter == 9){ //9の表示
            M5.dis.drawpix(1, COLOR[2]);
            M5.dis.drawpix(2, COLOR[2]);
            M5.dis.drawpix(3, COLOR[2]);
            M5.dis.drawpix(6, COLOR[2]);
            M5.dis.drawpix(8, COLOR[2]);
            M5.dis.drawpix(11, COLOR[2]);
            M5.dis.drawpix(12, COLOR[2]);
            M5.dis.drawpix(13, COLOR[2]);
            M5.dis.drawpix(18, COLOR[2]);
            M5.dis.drawpix(21, COLOR[2]);
            M5.dis.drawpix(22, COLOR[2]);
            M5.dis.drawpix(23, COLOR[2]);
        }
        M5.update();
        
    }
    
    delay(10); //ディレイ時間を長くしすぎると素早く入力した時に認識されない
    M5.update();
}
