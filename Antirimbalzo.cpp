
#include <Arduino.h>
#include "Antirimbalzo.h"
Antirimbalzo::Antirimbalzo() {
      periodocampionamento=1;
      somma=0;
      soglia=10;
      tPeriodoBlackOut=100;
      tDurataClickLungo=0;

}
void Antirimbalzo::Elabora(bool condizioneOn) {
	  
	  
      unsigned long now=millis();
      if( (now - tultimocampione) < periodocampionamento ) return;
      tultimocampione=now;
      //if(condizioneOn) {Serial.print("somma="); Serial.println(somma);}
      if(condizioneOn && somma==soglia-1) {
            if((now - tInizioStatoOn) > tPeriodoBlackOut) {
                  statoOnIniziato=true;
                  tInizioStatoOn=now;
                  if(cbInizioStatoOn) this->cbInizioStatoOn();
                  //Serial.println("iniziato");
            }
      }
      if(!condizioneOn && somma==1 && statoOnIniziato) {
            if((tDurataClickLungo >0) && (now - tInizioStatoOn) > tDurataClickLungo) {
                  if(cbClickLungo) this->cbClickLungo();
            } else if(cbClickCorto) this->cbClickCorto();
            statoOnIniziato=false;
            //Serial.print("finito d=");
            //Serial.println(now - tInizioStatoOn);
      }
      if(condizioneOn) somma++; else if(somma>0) somma--;
      if(somma>soglia) somma=soglia;
}
