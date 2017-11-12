
<center>
#Coursework 1


Joseph Mulray<br/>
COMP1211 <br/>
October 31 2017<br/>
</center>


<br/>
<br/>

#### 1. Convert the following binary numbers to base ten.


(a) 10 

(b) 27


<br/>
#### 2. Convert the following base ten numbers to binary.

(a) 101111

(b) 1111101110001


<br/>

#### 3. Add the following binary numbers:

(a) 110100010

(b) 101100000

(c) 1001110000


<br/>

#### 4. Multiply the following binary numbers:

(a) 1001110

(b) 101010101

<br/>

#### 5. Convert the following hexadecimal numbers directly to binary.


(a) 0110101011110100

<center>

| 6| A| F  | 4|
| -------|-----| -----| ----- |
|0110|1010|1111 |0100|

</center>


(b) 0010000010011001

<center>

| 2|0|9|9 |
| -------|-----| -----| ----- |
|0010|0000|1001|1001|

</center>



<br/>

#### 6. Convert the following binary numbers directly to hexadecimal.

(a) 9B3D
<center>

| 1001| 1011| 0011  | 1101|
| -------|-----| -----| -----|
|9|B|3|D|

</center>

(b) 488A

<center>


| 0100 | 1000| 1000  | 1010|
| -------|-----| -----| ----- |
|4|8|8|A|

</center>

<br/>

#### 7.Convert the following binary number to base ten (fixed point): 1101.01

(7) 13.25


<br/>

#### 8. Convert the base ten number 23.625 to fixed point binary.

(8) 10111.101

<br/>


#### 9. Calculate how the base 10 number 25.125 is represented as a 32 bit floating point number on a computer where (as is standard) the first bit is the sign, the next 8 bits are the exponent (represented in 127 bias notation) and the remaining 23 bits represent the mantissa (with the usual normalisation).



<strong>
Fixed point binary </strong>

25 =
<center>
 
| 16 | 8 | 4 | 2 | 1 |  
| -------|-----| -----|-----|-----|
|1|1|0|0|1|


</center>
.125 = 

<center>

| 1/2 | 1/4 | 1/8 | 
| -------|-----| -----|
|0|0|1|

</br>

| 25 | .125 | 
| -------|-----| 
|11001|.001|


$$25.125 = 11001.001$$

</center>
<strong>
Move decimal 4 places</strong>

$$11001.001$$ fixed point value


$$ 1.1001001 * 2 ^ 4$$ (gives you exponent value)

$$ 1.1001001 * 2^{100} $$ = 22.125  

<br/>
<br/>

<strong>Calculate exponent (127 bias)</strong>

$$4 + 127 = 131$$ (add 127 for 127 bias)


<center>

| 128 | 64| 32  | 16 | 8 | 4  | 2| 1|
| -------|-----|-----| -----|-----| -----| -----|-----|
|1|0|0|0|0|0| 1| 1|
</center>


$$131= 10000011 $$


<strong>Calculate mantissa</strong>

$$1.1001001$$

remove the 1. always going to be a 1, add zeros to fill in rest of binary values until 23 bits big

$$10010010000000000000000$$ = Mantissa

</br>


<center>

| Sign Bit | Exponent | Mantissa |
| -------|-----| -----| 
|0| 10000011 | 10010010000000000000000 |


0 10000011 10010010000000000000000 = $$25.125$$ =  $$ 1.1001001 * 2^{100} $$ 
</center>
</br>
Base 10 number is represented as a 32 bit floating point number on a computer where the first bit is the sign, the next 8 bits are the exponent and the remaining 23 bits represent the mantissa as:

$$0 10000011 10010010000000000000000$$

