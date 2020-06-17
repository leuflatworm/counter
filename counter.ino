

#include "M5Atom.h"
#include <EEPROM.h>


uint8_t counter = 0; //1の位カウンター
uint8_t counter10 = 0; //10の位カウンター


const CRGB COLOR[4] = { //色設定
  0xf00000,
  0x00f000,
  0x0000f0,
  0x707070
}; 

int NUM_0[12] = {1,2,3,6,8,11,13,16,18,21,22,23};
int NUM_1[8] = {1,2,7,12,17,21,22,23};
int NUM_2[11] = {1,2,3,8,11,12,13,16,21,22,23};
int NUM_3[11] = {1,2,3,8,11,12,13,18,21,22,23};
int NUM_4[9] = {1,3,6,8,11,12,13,18,23};
int NUM_5[11] = {1,2,3,6,11,12,13,18,21,22,23};
int NUM_6[12] = {1,2,3,6,11,12,13,16,18,21,22,23};
int NUM_7[7] = {1,2,3,8,13,18,23};
int NUM_8[13] = {1,2,3,6,8,11,12,13,16,18,21,22,23};
int NUM_9[12] = {1,2,3,6,8,11,12,13,18,21,22,23};




void LEDDISP(int *points, int points_num){
  for(int i;i<points_num;i++){
    M5.dis.drawpix(points[i], COLOR[2]);
  }
}

void setup() {
    M5.begin(true, false, true);
    delay(50);
    M5.dis.clear();
    
    for (int i=0; i<25; i++) { //中央3列の表示をリセット
      M5.dis.drawpix(i, 0x000000);
    }

    
    //最初に0を表示する
    LEDDISP(NUM_0, 12);
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
          LEDDISP(NUM_0, 12);
        }else if(counter == 1){ //1の表示
          LEDDISP(NUM_1, 8);
        }else if(counter == 2){ //2の表示
          LEDDISP(NUM_2, 11);
        }else if(counter == 3){ //3の表示
          LEDDISP(NUM_3, 11);
        }else if(counter == 4){ //4の表示
          LEDDISP(NUM_4, 9);
        }else if(counter == 5){ //5の表示
          LEDDISP(NUM_5, 11);
        }else if(counter == 6){ //6の表示
          LEDDISP(NUM_6, 12);
        }else if(counter == 7){ //7の表示
          LEDDISP(NUM_7, 7);
        }else if(counter == 8){ //8の表示
          LEDDISP(NUM_8, 13);
        }else if(counter == 9){ //9の表示
          LEDDISP(NUM_9, 12);
        }
        M5.update();
        
    }
    
    delay(50); //ディレイ時間を長くしすぎると素早く入力した時に認識されない
    M5.update();
}
