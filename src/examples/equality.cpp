#include <iostream>
#include "tfhe.h"
#include "polynomials.h"
#include "lwesamples.h"
#include "lwekey.h"
#include "lweparams.h"
#include "tlwe.h"
#include "tgsw.h"

// A function computing the equality between two encrypted messages. 
// 
// Arguments: 
//  * cipher1: pointer to an encryption of the first message m1
//  * cipher2: pointer to an encryption of the second message m2
//  * cipher3: pointer to a cipher which will encrypt the result 
//             (encryption of `true` if m1 = m2 or `false` otherwise)
//  * s1: length of m1
//  * s2: length of m2
//  * keyset: pointer to the bootstrapping key set
void are_equal(LweSample* cipher1, LweSample* cipher2, LweSample* cipher3, 
               unsigned int s1, unsigned int s2, 
               TFheGateBootstrappingSecretKeySet *keyset) 
{
    // If the messages have different lengths, we know that the messages are different. 
    // `*cipher3` should thus be an encryption of `false`.
    if (s1 != s2) {

        // For any boolean value b, XOR(b, b) is false. 
        // The next line will thus set `*cipher3` to an encryption of `false`.
        bootsXOR(cipher3, cipher1, cipher1, &keyset->cloud);

        // return, `*cipher3` already has the right result
        return;
    }

    // component-wise comparison
    for (unsigned int i=0; i<s1; i++)

        // Set the element of index `i` of `*cipher3` to an encryption of `true` if the 
        // corresponding elements of m1 and m2 are identical or `false` if they are different.
        bootsXNOR(cipher3+i, cipher1+i, cipher2+i, &keyset->cloud);

    // accumulate: set the element of index 0 of `*cipher3` to an encryption of `false` if at least
    // one of its element encrypts `false`
    for (unsigned int i=1; i<s1; i++)
        bootsAND(cipher3, cipher3+i, cipher3, &keyset->cloud);

    // `*cipher3` now encrypts `true` if m1 = m2 or `false` otherwise
}


int main(void) {

    // generate parameters
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
