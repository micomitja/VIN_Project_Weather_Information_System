# Arduino Weather Information System MasterReader/SlaveSender

## This severe weather Information system informs us about severe temperature or weather conditions on the place where this system is placed

Ta informativni sistem o vremenskih razmerah nas obvešča o hudih vremenskih oz temperaturnih razmerah na kraju, kjer je ta sistem postavljen (obvešča nas z rdečimi in modrimi LED-diodami in zvočnim opozorilom, vse pa je prikazano tudi na LCD zaslonu). zunanji element ima tudi kontrolno LED, ko je zunaj temno, da se vklopi.Če pa ne želimo zvočnih opozoril, lahko vse tudi utišamo z gumbom, ko sveti kontrolna lučka LED, vemo, da je naš sistem utišan in ne bo sprožil alarma, ko pride do hudih vremenskih razmer, tako hudih padcev ali dvigov temperature.

## Delovanje

zadeva je sledeča naredil sem preprost sistem z dvema Arduinoma, kjer sem uporabil nekaj različnih senzorjev, komponent na breadboard ploščicah in sem jih na koncu povezal v sistem. Ta sistem nas obvešča o nevarnih temperaturah (torej zelo nizke temperature in zelo visoke temperature), to sem storil na sledeč način sam LCD nam pove kakšna je temperatura, ter pove nam za kakšno vreme se gre, ter ali ta temperatura že predstavlja nevarnost za nas (npr. problem pretvarjanja enot temperatur). Zraven samega podatka o temperaturi nam LCD izpiše še podatek npr Cold, Chill, Warm, Hot, pa seveda Dangerous Temperaturo. Dodal sem še RGB LED diodo ki bi nas lahko na npr. zunanji enoti obvestila z svetlobnim signalom o kakšnih temperaturah se gre (npr. Rdeča pa Modra za Nevarne temperature (vroče, mrzlo) zelena za normalne temperature, zraven pa sem dodal že piezo zvočnik ki nas s piskanjem obvestil kadar gre za nevarne temperature, pa naj bo to zunaj ali pa v nekem kontroliranem okolju kjer ne rabimo vedeti veliko o temperaturi, samo potrebno je da je ta temperature v nekih mejah npr. hladilnice ali kaj podobnega kjer bi bila ena led dioda in pa piezo zvočnik bila dovolj da bi vedeli ali smo prostor preveč segreli med tem časom ko smo stvari uvažali notr, ker pa je to piskanje lahko ne zaželeno in moteče pa lahko to piskanje tudi utišamo in mutea-amo zato sem dodal tipko in pa kontrolno led diodo s katero vidimo kdaj je zvočnik utišan saj bi gorela led diod. Sistem pa ima tudi še fotoupor, ki deluje tako, da ko je dovolj temačno prižge led kontrolno led diodo in za npr. lažje lociranje temperaturne komponente, lahko pa bi tudi npr. prižgal luči oz. razsvetljavo ali kaj podobnega. LCD zaslonu pa sem dodal še dva potenciometra od katerih ima eden funkcijo za reguliranje osvetlitve LCD zaslona, drugi pa prižiga samega LCD zaslona.

Celoten sistem je povezan z uporabo dveh Arduinotov kjer je eden isključno povezan na Senzorje drug pa je povezan samo na LCD zaslon in nam izpisuje vse te podatke ki soj jih naši zunanji senzorji zajeli. in nam jih sporoči v obliki podatka o temperaturi na LCDju.

# Component List

| Quantity  | Component  |  
|---|---|
|2	  |   Arduino Uno  |
|1	  |     LED RGB  |
|1	  |     Orange LED  |
|1	  |     Yellow LED  |
|1   |   	White  LED  |
|1   |   	Photoresistor |
|1	  |     LCD 16 x 2  |
|1	  |     330 Ω Resistor  |
|6	  |     220 Ω Resistor  |
|2	  |     200 kΩ Potentiometer  |
|1	  |     Piezo |
|1	  |     Temperature Sensor [DHT-11] |
|1	  |     Pushbutton  |
|1	  |     10 kΩ Resistor  |


## Master Reader
![image](https://user-images.githubusercontent.com/56089916/121075443-7b911800-c7d5-11eb-8fb1-f7658df8cea3.png)
## Slave Sender 
![image](https://user-images.githubusercontent.com/56089916/121075549-995e7d00-c7d5-11eb-88ea-97f73a9c79dc.png)

# I2C:
Arduina sta povezana s povezana sinhronega serijskega protokola I2C (Inter-Integrated Circuit), gre pa za konfiguracijo Master Reader, Slave Sender.

V nekaterih primerih je lahko koristno, če nastavimo dve (ali več!) ploščic Arduino za izmenjavo informacij med seboj. V tem primeru sta dve plošči programirani za medsebojno komunikacijo v konfiguraciji Master Reader / Slave Sender prek sinhronega serijskega protokola I2C. Za to se uporablja več funkcij Arduino's Wire Library. Master Arduino 1 je programiran tako, da zahteva in nato prebere 6 bajtov podatkov, poslanih iz enolično naslovljenega Slave Arduina. Ko je to sporočilo prejeto, si ga lahko nato ogledate v oknu serijskega monitorja Arduino Software (IDE).

Protokol I2C vključuje uporabo dveh vrstic za pošiljanje in prejemanje podatkov: serial clock pin (SCL), ki ga plošča Arduino Master pulzira v rednem intervalu, in serial data pin(SDA), prek katerega se podatki pošiljajo med obema napravama. Ko se časovna linija spreminja iz nizke v visoko (imenovano naraščajoči rob impulza ure), se en bit informacij - ki bodo zaporedoma tvorili naslov določene naprave in ukaz ali podatki - prenese s plošče na napravo I2C prek linije SDA. Ko se te informacije pošljejo - bit za bitom - klicana naprava izvede zahtevo in svoje podatke pošlje nazaj - po potrebi - na ploščo preko iste črte, pri čemer kot časovni signal še vedno generira Master na SCL.

Ker protokol I2C omogoča, da ima vsaka omogočena naprava svoj edinstven naslov, in ker se tako Master kot Slave naprava izmenjata v eni liniji, lahko vaša plošča Arduino komunicira (po vrsti) s številnimi napravami oz. druge plošče, medtem ko uporabljate samo dva pina mikrokrmilnika

I2C Circuit

![image](https://user-images.githubusercontent.com/56089916/121073699-2227e980-c7d3-11eb-9ef1-507b01774f05.png)

I2C Schematic
![image](https://user-images.githubusercontent.com/56089916/121073708-26ec9d80-c7d3-11eb-951d-15a047835292.png)

I²C is a low speed 2-wire serial communication protocol for exchanging information betwwen one or more masters and multiple slave devices.


# DHT-11:
V projektu sem uporabil Temperatuni Senzor DHT-11

![image](https://user-images.githubusercontent.com/56089916/121074951-d8d89980-c7d4-11eb-8776-10a083ec946f.png)

![image](https://user-images.githubusercontent.com/56089916/121075105-11787300-c7d5-11eb-98d6-b37964bd10dc.png)


DHT-11 je digitalni senzor relativne vlage in temperature. Uporablja kapacitivni senzor vlage in termistor za merjenje okoliškega zraka. V primerjavi z DHT22 je ta senzor manj natančen, manj natančen in deluje v manjšem območju temperature in vlažnosti, vendar je manjši in cenejši.

Tehnične podrobnosti:
  - Moč: 3-5V
  - Tok: 2,5 mA
  - Vlažnost: 20-95%, ± 5% natančnost
  - Temperatura: -20 do 50 ° C, natančnost ± 2 °

![image](https://user-images.githubusercontent.com/56089916/121075032-f60d6800-c7d4-11eb-805c-d3d5bbbea716.png)


## Video

https://www.youtube.com/watch?v=u04du5kiCZ0


## Images
![image](https://user-images.githubusercontent.com/56089916/121075371-66b48480-c7d5-11eb-83e7-13f85a37f68f.png)

![image](https://user-images.githubusercontent.com/56089916/121075629-b5fab500-c7d5-11eb-93b9-fde9027abada.png)

![image](https://user-images.githubusercontent.com/56089916/121075689-ca3eb200-c7d5-11eb-9670-417a1f231b6f.png)

![image](https://user-images.githubusercontent.com/56089916/121075737-d88cce00-c7d5-11eb-82a1-68b05a439504.png)

![image](https://user-images.githubusercontent.com/56089916/121075796-e80c1700-c7d5-11eb-829d-ce496a5a1ba0.png)

![image](https://user-images.githubusercontent.com/56089916/121075894-06721280-c7d6-11eb-84fd-5d507aebb271.png)


# Project Schematics:

![image](https://user-images.githubusercontent.com/56089916/121078640-80f06180-c7d9-11eb-85fc-de9987cbaccc.png)

![image](https://user-images.githubusercontent.com/56089916/121078668-86e64280-c7d9-11eb-88df-edab435be81c.png)

![image](https://user-images.githubusercontent.com/56089916/121078686-8c438d00-c7d9-11eb-8e23-45209c16226f.png)


## Simple connection 
https://www.tinkercad.com/things/gJhm8eh1x2B

## implementation with I2C
https://www.tinkercad.com/things/2mpW45a3ZXm

## Simple I2C
https://www.tinkercad.com/things/2pJolJm8PTc-i2c/editel?sharecode=1RLWIIR5fa05DZfq_dwC7M04p_WcAvSfdoQNIG_1MDo

## Arduino Hub of those Sub Projects

https://create.arduino.cc/projecthub/micofri/weather-station-beta-severe-weather-information-system-f71aaf?auth_token=e94d5399bfcdd30b5c9e8afebb06c3a4

https://create.arduino.cc/projecthub/micofri/severe-weather-information-system-master-reader-slave-sender-ed7d80?auth_token=bbfe363653d89500cff1772e627e41fc

## Other LINKs Code 

https://create.arduino.cc/editor/micofri/e6bb6846-8216-491c-9056-6d1237731178/preview

https://create.arduino.cc/editor/micofri/e71c51ca-c839-4281-b9a5-a8d21f7f4908/preview
