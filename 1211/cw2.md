
<center>
#Coursework 2


Joseph Mulray<br/>
COMP1211 <br/>
November 23, 2017<br/>
</center>


<br/>
<br/>

#### 1 (a) How many bytes in total can be stored in the cache?

Block size is 32 bytes = $$2^4$$ = 4 bits

Lines is 32 bytes = $$2^4$$ = 4 bits

Cache size = $$2^4$$ x $$2^4$$ = $$2^8$$ = 256 bytes




256 bytes


<br/>
#### (b) Describe how the memory address is divided into tag, line number and byte number, giving the number of bits for each.


Block size is 32 bytes = $$2^4$$ = 4 bits

Lines is 32 bytes = $$2^4$$ = 4 bits

Main memory = 2Mbytes = $$2^{21}$$

Main memory can store $$2^{21}$$ bytes, so it requires a 21-bit
address

Tag is $$21 - (4 + 4)$$ = 13 bits


<center>

| Tag| Line| Word |
| :-------:|:-----:| :-----:| 
|13 bits |4 bits |4 bits|

</center>



<br/>

#### (c) Into which lines would bytes with each of the following addresses be stored

Line numbers:

(a) 13

(b) 3

(c) 13

(d) 10


<br/>

#### (d) What other bytes are stored along with it in the same cache line?

0000110000011 0001 0000 through 0000110000011 0001 1111 are stored in that line.




<br/>

#### 2. Describe how a main memory address is divided into tag, set number and byte number, giving the number of bits for each.

Main memory is 4Mbytes = $$2^2$$ x $$2^{22}$$ =  $$2^{24}$$ 

24bit memory address

Cache is 64Kbytes  = $$2^6$$ x $$2^{10}$$ = $$2^{16}$$

Block Size is 16bytes = $$2^4$$

Lines = $$2^{16}$$ / $$2^4$$  = $$2^{12}$$

Block Set (K) = 2




Since the blockset is 2 we reduce the Lines by half by removing one bit from Lines and moving it into tag leaving 11 bits to identify the Set and 7 bits to identify the Tag.



<center>

| Tag| Set| Word |
| :-------:|:-----:| :-----:| 
|7 bits|11 bits |4 bits|

</center>

<br/>



#### 3. Show the resulting changes to the values held in registers (PC, AC and IR) and memory when a computation is started with a value of 100 in the PC, and the following values held in memory:
<br/>
<center>

| PC| IR| AC | 520 | 521 | 522	
| :-------:|:-----:| :-----:| :-----:| :-----:| :-----:| 
|100| 4520| 0120|
|101| 8522| 0127|
|102| 6521| | | 0127

</center>