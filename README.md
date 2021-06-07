# Arduino Weather Information System MasterReader/SlaveSender

## This severe weather Information system informs us about severe temperature or weather conditions on the place where this system is placed

Ta informativni sistem o vremenskih razmerah nas obvešča o hudih vremenskih oz temperaturnih razmerah na kraju, kjer je ta sistem postavljen (obvešča nas z rdečimi in modrimi LED-diodami in zvočnim opozorilom, vse pa je prikazano tudi na LCD zaslonu). zunanji element ima tudi kontrolno LED, ko je zunaj temno, da se vklopi.Če pa ne želimo zvočnih opozoril, lahko vse tudi utišamo z gumbom, ko sveti kontrolna lučka LED, vemo, da je naš sistem utišan in ne bo sprožil alarma, ko pride do hudih vremenskih razmer, tako hudih padcev ali dvigov temperature.

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

## Simple connection 
https://www.tinkercad.com/things/gJhm8eh1x2B-weather-station-beta-severe-weather-information-system-with-one/editel?sharecode=ETO8rby8YnhPC1pKZn8wViG2POKvgpQ88V2Zn_p8FfQ

## implementation with I2C
https://www.tinkercad.com/things/2mpW45a3ZXm-severe-weather-information-system-master-readerslave-sender/editel?sharecode=My0bnswG5MtlrScEi1Kl48zGzEvXN0rk_vMMWDT7DdM

## Simple I2C
https://www.tinkercad.com/things/2pJolJm8PTc-i2c/editel?sharecode=1RLWIIR5fa05DZfq_dwC7M04p_WcAvSfdoQNIG_1MDo

## Arduino Hub of those Sub Projects

https://create.arduino.cc/projecthub/micofri/weather-station-beta-severe-weather-information-system-f71aaf?auth_token=e94d5399bfcdd30b5c9e8afebb06c3a4

https://create.arduino.cc/projecthub/micofri/severe-weather-information-system-master-reader-slave-sender-ed7d80?auth_token=bbfe363653d89500cff1772e627e41fc

## Other LINKs

https://create.arduino.cc/editor/micofri/e6bb6846-8216-491c-9056-6d1237731178/preview

https://create.arduino.cc/editor/micofri/e71c51ca-c839-4281-b9a5-a8d21f7f4908/preview
