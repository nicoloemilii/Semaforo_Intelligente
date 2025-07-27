# 🚦 Semaforo Intelligente

## 🧠 Descrizione del progetto
Questo progetto ha lo scopo di realizzare un **semaforo intelligente** dotato di:

- **Fotoresistenza** per la modalità Giorno/Notte  
- **Sensore ultrasuoni** per rilevare la presenza di veicoli  
- **Buzzer** per segnalazione acustica ai pedoni  
- **Pulsante pedonale** con gestione tramite interrupt  
- **Interruttore** per lo spegnimento e modalità lampeggiante  

Il sistema è stato sviluppato su **Arduino UNO R3** e consente una gestione avanzata del traffico simulato, migliorando la sicurezza dei pedoni e l'efficienza dei flussi stradali.

## 🚦 Funzionalità principali

- **Modalità Giorno**: sequenza semaforica standard
- **Modalità Notte**:
  - Se **nessuna vettura** transita sulla strada secondaria → verde per la via principale, rosso per la via secondaria
  - Se **una vettura** viene rilevata sulla via secondaria → passa alla sequenza Giorno
- **Prenotazione pedonale**:
  - Gestita con interrupt per non richiedere la pressione continua del pulsante
- **Segnalazione acustica**:
  - Suoni lenti per i primi 4 secondi
  - Suoni veloci 1 secondo prima dello scatto al rosso

## 🧩 Componenti utilizzati

- Arduino UNO R3  
- Sensore ultrasuoni HC-SR04  
- Fotoresistenza  
- Buzzer  
- Interruttore  
- Pulsante  
- 9 LED (3 rossi, 3 gialli, 3 verdi)  
- 9 Resistori da 220Ω  
- Resistore da 1kΩ  

## 🖥️ Pin e variabili

| Variabile | Pin Arduino | Descrizione |
|----------|-------------|-------------|
| R1       | 9           | LED Rosso via principale |
| G1       | 3           | LED Giallo via principale |
| V1       | 6           | LED Verde via principale |
| R2       | 4           | LED Rosso via secondaria |
| G2       | 5           | LED Giallo via secondaria |
| V2       | 7           | LED Verde via secondaria |
| PR       | 16          | LED Rosso pedone |
| PG       | 15          | LED Giallo pedone |
| PV       | 10          | LED Verde pedone |
| Fres     | A0          | Fotoresistenza |
| INT      | 8           | Interruttore |
| PD       | 2           | Pulsante pedone |
| BUZ      | 13          | Buzzer |
| TRIG     | 12          | Trigger sensore ultrasuoni |
| ECHO     | 11          | Echo sensore ultrasuoni |

## ⚙️ Calcolo distanza (ultrasuoni)
- Formula utilizzata:  
  **Spazio (cm) = 0,03431 × tempo (µs)**  
  (con velocità del suono a 343,1 m/s)

## 👨‍💻 Autore

Nicolò Emilii

---

