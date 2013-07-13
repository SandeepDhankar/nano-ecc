#include "ecc.h"

#include <stdarg.h>

void p(char *fmt, ... ){
    char tmp[128]; // resulting string limited to 128 chars
    va_list args;
    va_start (args, fmt );
    vsnprintf(tmp, 128, fmt, args);
    va_end (args);
    Serial.print(tmp);
}

void dump(char *text, uint8_t *d) {
    int i;
    p("%-20s", text);
    for (i = 0; i < NUM_ECC_DIGITS; ++i)
        p("%02x ", d[NUM_ECC_DIGITS-i-1]);
    Serial.print("\n");
}

void loop() {
    unsigned long then, now;

#if ECC_CURVE == secp128r1
    uint8_t private_0[NUM_ECC_DIGITS] = {0x01, 0x48, 0x04, 0x92, 0x75, 0xCC, 0xBB, 0xE2, 0xF4, 0xE9, 0x77, 0x00, 0x2C, 0x91, 0x45, 0xA3};
    EccPoint public_0 = {
        {0x52, 0x81, 0xA2, 0x99, 0xBD, 0x47, 0xDF, 0x2D, 0xFB, 0x74, 0xF4, 0x3E, 0xBB, 0x03, 0x23, 0xDE},
        {0xE0, 0x75, 0xB2, 0x4F, 0x8F, 0xA7, 0x4C, 0xB8, 0x59, 0x8A, 0x8B, 0x3B, 0x6A, 0x52, 0xA0, 0xE4}};

    uint8_t private_1[NUM_ECC_DIGITS] = {0x86, 0x12, 0x9B, 0x67, 0xCB, 0x4D, 0x8C, 0x33, 0x09, 0xBD, 0x05, 0x1B, 0xF8, 0xE2, 0x9D, 0x76};
    EccPoint public_1 = {
        {0x72, 0xE2, 0x5E, 0xAD, 0xB7, 0x01, 0x5D, 0xF9, 0xD5, 0xCA, 0xFF, 0x8A, 0xE3, 0x42, 0xAE, 0x3C},
        {0x42, 0x67, 0x7F, 0x53, 0x54, 0x17, 0x84, 0xCB, 0x64, 0xFA, 0xD6, 0x3A, 0xE8, 0x22, 0x06, 0x28}};
#elif ECC_CURVE == secp192r1
    uint8_t private_0[NUM_ECC_DIGITS] = {0x57, 0x30, 0xE4, 0x74, 0x4D, 0xE9, 0x61, 0xE0, 0xF7, 0x63, 0x23, 0xA0, 0x08, 0x66, 0xFC, 0x69, 0xE2, 0x71, 0x70, 0xCE, 0xDA, 0x8F, 0x84, 0x0A};
    EccPoint public_0 = {
        {0x82, 0xFD, 0x02, 0x0D, 0xE9, 0x36, 0x15, 0x3B, 0xDA, 0x93, 0x08, 0x92, 0x59, 0x97, 0x15, 0xE9, 0xF5, 0xF4, 0xAE, 0xF3, 0xDA, 0x56, 0x2E, 0xB4},
        {0xD7, 0xFD, 0xFE, 0xCD, 0x99, 0x2E, 0xC9, 0x51, 0xE8, 0x3B, 0xA3, 0x4F, 0x54, 0xF6, 0x12, 0x1D, 0xC1, 0x77, 0xA3, 0x43, 0x80, 0x6C, 0x65, 0x67}};

    uint8_t private_1[NUM_ECC_DIGITS] = {0x08, 0x47, 0xD8, 0x66, 0x6A, 0x96, 0xFE, 0x6A, 0x19, 0x3F, 0x1F, 0xB6, 0x01, 0xF5, 0x75, 0x1C, 0xFF, 0x7B, 0xFA, 0xD2, 0xB8, 0x6B, 0xEF, 0x17,};
    EccPoint public_1 = {
        {0xB3, 0xF2, 0x06, 0x79, 0x33, 0x07, 0x68, 0xA0, 0x0E, 0xDE, 0x6C, 0x4A, 0xD2, 0xCA, 0xB5, 0x36, 0x9E, 0x9D, 0x1F, 0x7A, 0xFF, 0xDE, 0xDA, 0x61,},
        {0x4F, 0x48, 0x19, 0x11, 0x56, 0x52, 0x24, 0x9E, 0xA6, 0xDE, 0x5C, 0xCD, 0x9A, 0xBA, 0x02, 0xC0, 0xB2, 0x6F, 0xA6, 0x53, 0x49, 0x61, 0x3E, 0xE6}};
#elif ECC_CURVE == secp384r1
    uint8_t private_0[NUM_ECC_DIGITS] = {0x45, 0xB1, 0xED, 0x13, 0x86, 0x38, 0xC6, 0x98, 0xFA, 0xDC, 0xC6, 0x4C, 0x82, 0x11, 0x56, 0xFE, 0x70, 0x3E, 0xC1, 0xD3, 0x0C, 0x85, 0xAA, 0x5C, 0xEC, 0x01, 0x4B, 0x6C, 0x9A, 0xE0, 0xF2, 0x54, 0xAC, 0x3F, 0x0A, 0x64, 0x83, 0xF6, 0x31, 0x1B, 0xEB, 0xC1, 0x67, 0xC2, 0xE3, 0xD1, 0xDF, 0x4C};
    EccPoint public_0 = {
        {0xED, 0xCD, 0x7E, 0xB1, 0x69, 0xCF, 0xC9, 0x03, 0xCB, 0xFF, 0xEA, 0xE6, 0x65, 0x7E, 0x8B, 0xD3, 0x6D, 0x5A, 0x6C, 0x85, 0x4C, 0x0A, 0x17, 0xCA, 0x84, 0x40, 0x3D, 0x92, 0xA4, 0x36, 0xD1, 0xA8, 0xB1, 0x31, 0xDD, 0x80, 0xC5, 0xC5, 0xEC, 0x02, 0x34, 0xF2, 0x00, 0xEA, 0x51, 0xAD, 0x7B, 0x00},
        {0xB3, 0x97, 0x2C, 0x15, 0xEE, 0x98, 0x52, 0xF9, 0xD6, 0x57, 0xF0, 0x0B, 0xD6, 0x0B, 0x6B, 0x42, 0x0B, 0xF3, 0x35, 0x88, 0x0A, 0xFA, 0xDF, 0xE3, 0xC4, 0x7C, 0xE1, 0x7F, 0x41, 0x43, 0x89, 0x8B, 0xE2, 0x04, 0x95, 0x91, 0xB7, 0xFD, 0xC7, 0xDF, 0xA8, 0x63, 0x26, 0x79, 0xAE, 0xF7, 0x2E, 0x03}};

    uint8_t private_1[NUM_ECC_DIGITS] = {0xFC, 0x8A, 0x80, 0x56, 0x5C, 0xAC, 0x0C, 0x31, 0xE5, 0xEE, 0xC1, 0x36, 0xB1, 0xB5, 0x16, 0xED, 0x09, 0x2D, 0xB3, 0xF9, 0x3F, 0x00, 0x20, 0xC1, 0xB1, 0x26, 0x9A, 0xC7, 0x32, 0x3D, 0x49, 0x7A, 0xD3, 0xDE, 0x2C, 0x87, 0x18, 0xC3, 0xE6, 0xCA, 0xDA, 0x10, 0xF1, 0x0A, 0x4D, 0x65, 0x7C, 0x14};
    EccPoint public_1 = {
        {0x78, 0xA4, 0xE7, 0x61, 0xC7, 0xA6, 0x7C, 0x60, 0x65, 0xFD, 0x34, 0x72, 0x61, 0xCE, 0x74, 0xFA, 0x23, 0x32, 0x9B, 0x0D, 0x7D, 0x41, 0x4B, 0xB5, 0x98, 0xCD, 0x95, 0x63, 0x09, 0xCD, 0xA6, 0x90, 0xCF, 0x62, 0xF4, 0x60, 0x25, 0x88, 0x12, 0x2B, 0xC8, 0x4B, 0xD1, 0x29, 0x30, 0x95, 0x9A, 0x51},
        {0x8A, 0xC9, 0x99, 0xA1, 0xCE, 0x85, 0xC7, 0xD0, 0x39, 0x79, 0x34, 0x74, 0x33, 0x77, 0x22, 0x39, 0x0F, 0x94, 0x88, 0xB8, 0x52, 0xCF, 0x9A, 0x55, 0x7A, 0xE1, 0x62, 0x91, 0x8E, 0x87, 0x4E, 0xF5, 0xD1, 0xC8, 0x54, 0x32, 0xE3, 0xCE, 0xD5, 0xA7, 0x3B, 0x72, 0xE0, 0x0F, 0x89, 0x6D, 0xD5, 0xF2}};
#endif

    uint8_t private_2[NUM_ECC_DIGITS];
    EccPoint public_2;
    
    then = millis();
    /*
    Serial.print("generating public key..");
    ecc_make_key(&public_2, private_2, private_0);
    now = millis();
    p(" %u ms\n", now-then);
    
    dump("old", public_0.x);
    dump("new", public_2.x);
    */
 
    Serial.print("ecdh..");
    
    then = millis();
    uint8_t secret_0[NUM_ECC_DIGITS] = { 0, };
    ecdh_shared_secret(secret_0, &public_0, private_1, NULL);
    now = millis();
    p(" %u ms\n", now-then);

    dump("secret", secret_0);
}

void setup() {
    Serial.begin(115200);
}