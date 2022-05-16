#include <iostream>
#include "tfhe.h"
#include "polynomials.h"
#include "lwesamples.h"
#include "lwekey.h"
#include "lweparams.h"
#include "tlwe.h"
#include "tgsw.h"

void are_equal(LweSample* cipher1, LweSample* cipher2, LweSample* cipher3, 
               unsigned int s1, unsigned int s2, 
               TFheGateBootstrappingSecretKeySet *keyset) 
{
    // if the messages have different lengths, return an encryption of `false`
    if (s1 != s2) {
        bootsXOR(cipher3, cipher1, cipher1, &keyset->cloud);
        return;
    }

    // component-wise comparison
    for (unsigned int i=0; i<s1; i++)
        bootsXNOR(cipher3+i, cipher1+i, cipher2+i, &keyset->cloud);

    // accumulate
    for (unsigned int i=1; i<s1; i++)
        bootsAND(cipher3, cipher3+i, cipher3, &keyset->cloud);
}

int main(void) {

    // generate params 
    int32_t minimum_lambda = 100;
    TFheGateBootstrappingParameterSet *params = new_default_gate_bootstrapping_parameters(minimum_lambda);
    const LweParams *in_out_params = params->in_out_params;

    // generate the secret keyset
    TFheGateBootstrappingSecretKeySet *keyset = new_random_gate_bootstrapping_secret_keyset(params);

    // get the two messages from the user
    std::vector<bool> m1, m2;
    std::string m1_s, m2_s;
    std::cout << "Message 1: ";
    getline(std::cin, m1_s);
    for (unsigned int i=0; i<m1_s.size(); i++) {
        m1.push_back(m1_s[i] & 1);
        m1.push_back(m1_s[i] & 2);
        m1.push_back(m1_s[i] & 4);
        m1.push_back(m1_s[i] & 8);
        m1.push_back(m1_s[i] & 16);
        m1.push_back(m1_s[i] & 32);
        m1.push_back(m1_s[i] & 64);
        m1.push_back(m1_s[i] & 128);
    }
    std::cout << "Message 2: ";
    getline(std::cin, m2_s);
    for (unsigned int i=0; i<m2_s.size(); i++) {
        m2.push_back(m2_s[i] & 1);
        m2.push_back(m2_s[i] & 2);
        m2.push_back(m2_s[i] & 4);
        m2.push_back(m2_s[i] & 8);
        m2.push_back(m2_s[i] & 16);
        m2.push_back(m2_s[i] & 32);
        m2.push_back(m2_s[i] & 64);
        m2.push_back(m2_s[i] & 128);
    }
    
    // encrypt the messages
    LweSample *cipher1 = new_LweSample_array(m1.size(), in_out_params);
    LweSample *cipher2 = new_LweSample_array(m2.size(), in_out_params);
    for (unsigned int i = 0; i < m1.size(); ++i)
        bootsSymEncrypt(cipher1 + i, m1[i], keyset);
    for (unsigned int i = 0; i < m2.size(); ++i)
        bootsSymEncrypt(cipher2 + i, m2[i], keyset);

    // check the equality
    LweSample *cipher3 = new_LweSample_array(m1.size(), in_out_params);
    are_equal(cipher1, cipher2, cipher3, m1.size(), m2.size(), keyset);
    
    // decrypt the result
    bool res = bootsSymDecrypt(cipher3, keyset);
    
    if (res)
        std::cout << "The messages are equal" << std::endl;
    else 
        std::cout << "The messages are different" << std::endl;
    
    // free the memory
    delete_LweSample_array(m1.size(), cipher1);
    delete_LweSample_array(m2.size(), cipher2);
    delete_LweSample_array(m1.size(), cipher3);
    delete_gate_bootstrapping_secret_keyset(keyset);
    delete_gate_bootstrapping_parameters(params);

    return 0;
}
