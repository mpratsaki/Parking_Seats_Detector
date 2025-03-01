#include <MKL25Z4.H>
#include <stdio.h>

// Synartisi Assembly gia elegxo katastasis
__asm void Omada9(int *weightSensor, int *parkingSpots, int *motorControl, int *ledState) {
    LDR R2, [R0]        // Fortose tin timi tou weightSensor ston R2
    CMP R2, #1          // Elegxos an yparxei aftokinito (weightSensor == 1)
    BNE no_car          // An den yparxei aftokinito, pigene stin etiketa no_car

    LDR R3, [R1]        // Fortose tin timi tou parkingSpots ston R3
    CMP R3, #0          // Elegxos an yparxoun diathesimes theseis
    BEQ no_spots        // An den yparxoun diathesimes theseis, pigene stin etiketa no_spots

    MOVS R4, #0         // Rythmise to motorControl se 0 (anebasma mparas)
    STR R4, [R5]        // Apothikefse tin nea timi sto motorControl

    SUBS R3, R3, #1     // Meiose ton arithmo ton diathesimon theseon kata 1
    STR R3, [R1]        // Apothikefse tin enimeromeni timi sto parkingSpots
    B end_check         // Pigene sto telos tis synartisis

no_spots
    MOVS R4, #1         // Energopoiise to LED (endeixi oti to parking einai gemato)
    STR R4, [R3]        // Apothikefse tin nea timi sto ledState
    B end_check         // Pigene sto telos tis synartisis

no_car
    MOVS R4, #1         // Rythmise to motorControl se 1 (katevasma mparas)
    STR R4, [R2]        // Apothikefse tin nea timi sto motorControl

end_check
    BX LR               // Epistrofi apo ti synartisi
}

int main(void) {
    int weightSensor = 0;    // Arxiki katastasi: yparxei aftokinito
    int parkingSpots = 5;    // Arxikos arithmos diathesimon theseon
    int motorControl = 1;    // Katastasi elegxou motor (1 = katevasma)
    int ledState = 0;        // Katastasi LED (0 = svismeno)

    while (1) {              // Atermwn vrogxos gia tin parakolouthisi tis katastasis
        weightSensor = 0;    // Prosomiosi oti anixneyetai aftokinito ston aisthitira

        // Klisi tis synartisis Assembly gia diaxeirisi ton katastaseon
        Omada9(&weightSensor, &parkingSpots, &motorControl, &ledState);

        if (motorControl == 0) { // An to motor anevei tin mpara
            printf("Bar Up - Parking Spot Assigned: %d\n", parkingSpots);
            weightSensor = 0;    // Epanafora tou aisthitira varous
            motorControl = 1;    // Epanafora tis katastasis tou motor
        }

        if (ledState) {          // An to LED einai energopoihmeno (parking gemato)
            printf("Parking Full - LED ON\n"); // Emfanisi minimatos
        }
    }
}
