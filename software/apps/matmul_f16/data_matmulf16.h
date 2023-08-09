// Copyright 2022 ETH Zurich and University of Bologna.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
 
#define matrix_M (16)
#define matrix_N (16)
#define matrix_P (16)

__fp16 A[256] = {
0.50146484375f, 0.1202392578125f, 0.437255859375f, 0.42333984375f, 0.677734375f, 0.0164642333984375f, 0.1549072265625f, 0.09661865234375f, 
0.91650390625f, 0.92333984375f, 0.431396484375f, 0.60888671875f, 0.294189453125f, 0.7470703125f, 0.24658203125f, 0.89794921875f, 
0.74365234375f, 0.48828125f, 0.2308349609375f, 0.7177734375f, 0.09564208984375f, 0.040863037109375f, 0.93701171875f, 0.93017578125f, 
0.63037109375f, 0.42578125f, 0.8955078125f, 0.57763671875f, 0.494384765625f, 0.394287109375f, 0.11712646484375f, 0.736328125f, 
0.63427734375f, 0.67529296875f, 0.2471923828125f, 0.72998046875f, 0.52880859375f, 0.070556640625f, 0.066162109375f, 0.22412109375f, 
0.415283203125f, 0.8115234375f, 0.876953125f, 0.81103515625f, 0.334716796875f, 0.431640625f, 0.25244140625f, 0.449951171875f, 
0.2354736328125f, 0.40869140625f, 0.35986328125f, 0.73828125f, 0.376953125f, 0.98779296875f, 0.260009765625f, 0.69140625f, 
0.70947265625f, 0.82958984375f, 0.28564453125f, 0.625f, 0.2144775390625f, 0.457763671875f, 0.9267578125f, 0.80078125f, 
0.2115478515625f, 0.63818359375f, 0.57470703125f, 0.464111328125f, 0.85400390625f, 0.270751953125f, 0.6083984375f, 0.7431640625f, 
0.81103515625f, 0.1668701171875f, 0.6796875f, 0.75390625f, 0.51025390625f, 0.7919921875f, 0.1517333984375f, 0.4990234375f, 
0.66943359375f, 0.427734375f, 0.1534423828125f, 0.1163330078125f, 0.96875f, 0.283203125f, 0.057037353515625f, 0.35595703125f, 
0.7109375f, 0.103271484375f, 0.345703125f, 0.12030029296875f, 0.4404296875f, 0.79345703125f, 0.912109375f, 0.83935546875f, 
0.66748046875f, 0.4384765625f, 0.40234375f, 0.0921630859375f, 0.00982666015625f, 0.60498046875f, 0.06964111328125f, 0.5087890625f, 
0.18212890625f, 0.314453125f, 0.79248046875f, 0.791015625f, 0.9853515625f, 0.70947265625f, 0.39990234375f, 0.79931640625f, 
0.412109375f, 0.10589599609375f, 0.814453125f, 0.71484375f, 0.76220703125f, 0.9267578125f, 0.8349609375f, 0.51953125f, 
0.409423828125f, 0.45458984375f, 0.9462890625f, 0.069091796875f, 0.8330078125f, 0.63671875f, 0.62255859375f, 0.99365234375f, 
0.266357421875f, 0.67578125f, 0.4423828125f, 0.78369140625f, 0.5205078125f, 0.541015625f, 0.4765625f, 0.0227508544921875f, 
0.87353515625f, 0.01116943359375f, 0.199462890625f, 0.1463623046875f, 0.8349609375f, 0.84423828125f, 0.313720703125f, 0.02545166015625f, 
0.95458984375f, 0.796875f, 0.8046875f, 0.54833984375f, 0.9990234375f, 0.23291015625f, 0.900390625f, 0.810546875f, 
0.372802734375f, 0.019866943359375f, 0.20654296875f, 0.09295654296875f, 0.11614990234375f, 0.2154541015625f, 0.623046875f, 0.8251953125f, 
0.60009765625f, 0.96728515625f, 0.36865234375f, 0.1546630859375f, 0.8310546875f, 0.18408203125f, 0.351318359375f, 0.52197265625f, 
0.302001953125f, 0.91064453125f, 0.67529296875f, 0.051727294921875f, 0.175048828125f, 0.6494140625f, 0.73974609375f, 0.42236328125f, 
0.11065673828125f, 0.75634765625f, 0.335205078125f, 0.45458984375f, 0.78271484375f, 0.26025390625f, 0.5361328125f, 0.47705078125f, 
0.1878662109375f, 0.66455078125f, 0.143798828125f, 0.943359375f, 0.541015625f, 0.6904296875f, 0.24169921875f, 0.337158203125f, 
0.240966796875f, 0.1837158203125f, 0.191650390625f, 0.63330078125f, 0.51220703125f, 0.3408203125f, 0.783203125f, 0.87158203125f, 
0.74755859375f, 0.245849609375f, 0.51953125f, 0.83349609375f, 0.273193359375f, 0.79443359375f, 0.97412109375f, 0.351318359375f, 
0.25634765625f, 0.4931640625f, 0.72216796875f, 0.197998046875f, 0.68994140625f, 0.81884765625f, 0.3984375f, 0.1796875f, 
0.5927734375f, 0.6484375f, 0.6787109375f, 0.033843994140625f, 0.181884765625f, 0.70849609375f, 0.87744140625f, 0.6025390625f, 
0.76708984375f, 0.88232421875f, 0.73779296875f, 0.306396484375f, 0.1201171875f, 0.92333984375f, 0.42333984375f, 0.499755859375f, 
0.1142578125f, 0.3583984375f, 0.3232421875f, 0.7412109375f, 0.900390625f, 0.79052734375f, 0.97021484375f, 0.87939453125f, 
0.884765625f, 0.8447265625f, 0.01447296142578125f, 0.74755859375f, 0.191162109375f, 0.0457763671875f, 0.5068359375f, 0.93701171875f, 
0.2283935546875f, 0.376220703125f, 0.54345703125f, 0.98583984375f, 0.1920166015625f, 0.68701171875f, 0.87939453125f, 0.2900390625f,};

__fp16 B[256] = {
0.94873046875f, 0.05267333984375f, 0.89306640625f, 0.72119140625f, 0.002094268798828125f, 0.4697265625f, 0.83203125f, 0.85107421875f, 
0.505859375f, 0.81396484375f, 0.05657958984375f, 0.344970703125f, 0.473876953125f, 0.08465576171875f, 0.80029296875f, 0.64599609375f, 
0.302490234375f, 0.85888671875f, 0.779296875f, 0.72265625f, 0.671875f, 0.56591796875f, 0.285888671875f, 0.9296875f, 
0.75048828125f, 0.212646484375f, 0.7587890625f, 0.36669921875f, 0.98291015625f, 0.423095703125f, 0.50732421875f, 0.0212554931640625f, 
0.95556640625f, 0.47802734375f, 0.94140625f, 0.8740234375f, 0.9697265625f, 0.2110595703125f, 0.501953125f, 0.52783203125f, 
0.09405517578125f, 0.8154296875f, 0.66845703125f, 0.326416015625f, 0.358642578125f, 0.30517578125f, 0.9609375f, 0.6611328125f, 
0.4287109375f, 0.1553955078125f, 0.1448974609375f, 0.5693359375f, 0.9990234375f, 0.662109375f, 0.10858154296875f, 0.370849609375f, 
0.60546875f, 0.3388671875f, 0.01078033447265625f, 0.34033203125f, 0.00801849365234375f, 0.77001953125f, 0.477294921875f, 0.53369140625f, 
0.08831787109375f, 0.069091796875f, 0.485595703125f, 0.0271759033203125f, 0.99365234375f, 0.69873046875f, 0.267822265625f, 0.9482421875f, 
0.67822265625f, 0.51025390625f, 0.75048828125f, 0.5244140625f, 0.1484375f, 0.85498046875f, 0.29150390625f, 0.3046875f, 
0.65771484375f, 0.94873046875f, 0.66796875f, 0.2313232421875f, 0.55859375f, 0.990234375f, 0.9052734375f, 0.1761474609375f, 
0.97607421875f, 0.098388671875f, 0.837890625f, 0.264404296875f, 0.0631103515625f, 0.422607421875f, 0.6162109375f, 0.168701171875f, 
0.99072265625f, 0.5185546875f, 0.90478515625f, 0.5f, 0.33447265625f, 0.05126953125f, 0.9267578125f, 0.31640625f, 
0.286865234375f, 0.40234375f, 0.86962890625f, 0.31396484375f, 0.6640625f, 0.220458984375f, 0.56787109375f, 0.51123046875f, 
0.5556640625f, 0.25341796875f, 0.8955078125f, 0.85791015625f, 0.67138671875f, 0.88916015625f, 0.73291015625f, 0.994140625f, 
0.2100830078125f, 0.986328125f, 0.1365966796875f, 0.035186767578125f, 0.70751953125f, 0.322265625f, 0.20947265625f, 0.7373046875f, 
0.052642822265625f, 0.371826171875f, 0.354248046875f, 0.05755615234375f, 0.15966796875f, 0.8505859375f, 0.9619140625f, 0.353759765625f, 
0.0792236328125f, 0.78173828125f, 0.5302734375f, 0.433349609375f, 0.828125f, 0.1727294921875f, 0.5322265625f, 0.25927734375f, 
0.42333984375f, 0.87158203125f, 0.56640625f, 0.57080078125f, 0.1708984375f, 0.837890625f, 0.5556640625f, 0.33642578125f, 
0.35009765625f, 0.919921875f, 0.214599609375f, 0.83447265625f, 0.1275634765625f, 0.19091796875f, 0.89501953125f, 0.6748046875f, 
0.7626953125f, 0.6630859375f, 0.62744140625f, 0.69091796875f, 0.533203125f, 0.70947265625f, 0.032440185546875f, 0.66650390625f, 
0.1630859375f, 0.60888671875f, 0.56396484375f, 0.58984375f, 0.43896484375f, 0.72607421875f, 0.1898193359375f, 0.0018453598022460938f, 
0.79150390625f, 0.8193359375f, 0.82958984375f, 0.87744140625f, 0.6884765625f, 0.0289154052734375f, 0.463623046875f, 0.77685546875f, 
0.99462890625f, 0.1187744140625f, 0.313232421875f, 0.020751953125f, 0.87255859375f, 0.6337890625f, 0.179931640625f, 0.75146484375f, 
0.19873046875f, 0.416748046875f, 0.213134765625f, 0.477783203125f, 0.7080078125f, 0.4375f, 0.07861328125f, 0.2578125f, 
0.60498046875f, 0.266357421875f, 0.63232421875f, 0.419189453125f, 0.7861328125f, 0.72412109375f, 0.767578125f, 0.5244140625f, 
0.72119140625f, 0.1387939453125f, 0.51513671875f, 0.90966796875f, 0.267578125f, 0.266357421875f, 0.1893310546875f, 0.410888671875f, 
0.1409912109375f, 0.9326171875f, 0.9072265625f, 0.60693359375f, 0.6806640625f, 0.1744384765625f, 0.2626953125f, 0.34765625f, 
0.1705322265625f, 0.52490234375f, 0.7880859375f, 0.40185546875f, 0.84326171875f, 0.96240234375f, 0.71875f, 0.76953125f, 
0.62548828125f, 0.145751953125f, 0.73681640625f, 0.30126953125f, 0.5283203125f, 0.012237548828125f, 0.2425537109375f, 0.8447265625f, 
0.78662109375f, 0.82763671875f, 0.215087890625f, 0.293212890625f, 0.5205078125f, 0.8662109375f, 0.2261962890625f, 0.337890625f, 
0.97998046875f, 0.28466796875f, 0.169189453125f, 0.80419921875f, 0.56787109375f, 0.1944580078125f, 0.324951171875f, 0.1800537109375f,};

__fp16 C[256] = {
3.984375f, 3.6015625f, 4.0390625f, 3.849609375f, 3.765625f, 4.48046875f, 3.36328125f, 3.98828125f, 
3.5703125f, 4.40625f, 3.40234375f, 3.72265625f, 3.765625f, 2.759765625f, 3.6796875f, 3.3046875f, 
5.19921875f, 4.05078125f, 5.18359375f, 5.04296875f, 4.3125f, 4.75f, 4.0703125f, 4.8359375f, 
3.837890625f, 4.7109375f, 3.615234375f, 3.38671875f, 4.828125f, 3.275390625f, 3.927734375f, 3.7421875f, 
4.08984375f, 3.8515625f, 4.4140625f, 4.421875f, 4.19140625f, 4.4296875f, 3.001953125f, 4.5703125f, 
3.916015625f, 3.990234375f, 3.2734375f, 3.3515625f, 3.830078125f, 3.330078125f, 3.5546875f, 3.236328125f, 
4.59375f, 4.9140625f, 5.2734375f, 4.546875f, 5.1484375f, 6.09765625f, 4.7109375f, 4.77734375f, 
4.91796875f, 4.3125f, 4.28125f, 3.63671875f, 4.21484375f, 3.177734375f, 4.16015625f, 4.12890625f, 
4.73046875f, 4.05859375f, 5.28515625f, 4.8515625f, 5.15234375f, 4.79296875f, 3.935546875f, 5.1640625f, 
4.08203125f, 4.703125f, 4.70703125f, 3.4375f, 4.96484375f, 3.7890625f, 3.828125f, 3.595703125f, 
3.40234375f, 3.09765625f, 4.15234375f, 3.40625f, 4.0625f, 4.890625f, 3.435546875f, 4.46875f, 
3.80859375f, 3.80078125f, 3.97265625f, 3.306640625f, 3.947265625f, 2.55078125f, 3.1171875f, 3.013671875f, 
4.71875f, 4.25390625f, 4.71484375f, 4.7578125f, 4.1796875f, 4.46875f, 3.302734375f, 4.30078125f, 
4.25390625f, 3.80859375f, 3.83984375f, 3.19140625f, 4.48828125f, 3.044921875f, 3.6796875f, 3.373046875f, 
5.8046875f, 4.92578125f, 5.79296875f, 5.10546875f, 5.9765625f, 6.25f, 4.625f, 5.0859375f, 
4.9375f, 5.10546875f, 5.40234375f, 4.453125f, 4.54296875f, 4.078125f, 4.98046875f, 4.21484375f, 
3.26953125f, 2.966796875f, 3.7890625f, 3.53515625f, 4.10546875f, 3.876953125f, 3.1875f, 3.513671875f, 
3.27734375f, 3.4140625f, 4.24609375f, 2.802734375f, 3.75f, 2.984375f, 3.6015625f, 2.75390625f, 
4.92578125f, 3.625f, 5.64453125f, 4.5078125f, 5.1640625f, 5.03125f, 4.49609375f, 5.484375f, 
4.28515625f, 4.48828125f, 4.2578125f, 3.30078125f, 4.3828125f, 3.064453125f, 4.15625f, 3.8515625f, 
4.03125f, 3.90625f, 5.10546875f, 4.375f, 4.30078125f, 5.08203125f, 3.681640625f, 5.0390625f, 
3.689453125f, 4.515625f, 4.23828125f, 3.66796875f, 4.0234375f, 2.8046875f, 3.798828125f, 3.3359375f, 
3.9453125f, 3.830078125f, 4.5859375f, 4.3359375f, 4.52734375f, 3.8984375f, 3.232421875f, 4.41796875f, 
4.0859375f, 3.666015625f, 3.96875f, 2.974609375f, 4.0859375f, 3.275390625f, 3.4609375f, 3.455078125f, 
4.5390625f, 3.892578125f, 5.328125f, 4.6875f, 4.91015625f, 4.99609375f, 4.4375f, 4.9765625f, 
4.0390625f, 4.35546875f, 4.43359375f, 3.08984375f, 4.6796875f, 3.177734375f, 3.39453125f, 4.17578125f, 
4.28125f, 4.28515625f, 4.98046875f, 4.01171875f, 4.58984375f, 5.3203125f, 4.046875f, 4.359375f, 
3.875f, 4.2265625f, 4.80078125f, 3.736328125f, 3.744140625f, 2.80859375f, 3.978515625f, 3.25390625f, 
5.7421875f, 5.328125f, 6.23046875f, 5.75f, 5.6171875f, 5.62890625f, 4.69921875f, 5.4375f, 
5.5625f, 4.40625f, 5.2109375f, 3.802734375f, 5.39453125f, 3.412109375f, 4.86328125f, 4.49609375f, 
4.77734375f, 3.91015625f, 5.59375f, 5.3828125f, 4.625f, 4.71875f, 4.0625f, 5.546875f, 
4.3203125f, 4.26953125f, 3.71875f, 2.927734375f, 4.875f, 3.06640625f, 3.44921875f, 4.203125f,};