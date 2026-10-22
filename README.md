_________________________________________________________
""IMPLEMENTATION OF ERROR CORRECTION CODE --CRC USING C/JAVA""
---OUTPUT---
_________________________________________________________

--- SENDER SIDE ---
Enter Raw Data Bits: 100100
Enter Generator Polynomial Bits: 100
Generated CRC Checksum: 00
Codeword Transmitted over Network: 10010000

--- RECEIVER SIDE ---
Enter Received Codeword Stream: 100100100
Resulting Remainder: 00
Status: SUCCESS! Data received flawlessly with zero errors.


...Program finished with exit code 0
Press ENTER to exit console.

_________________________________________________________
""IMPLEMENT THE SLIDING WINDOW PROTOCOL USING JAVA/C""
---OUTPUT---
__________________________________________________________
Enter the sliding window size: 3
Enter total number of frames to transmit: 7
Enter the values/sequence numbers for 7 frames:
10 20 30 40 50 60 70

--- Starting Sliding Window Protocol Simulation ---

Sender transmits frames: 10 20 30 
Receiver processing... Generating ACKs...
Acknowledgement for Frame 10 received.
Acknowledgement for Frame 20 received.
Acknowledgement for Frame 30 received.
--> Window slides forward.

Sender transmits frames: 40 50 60 
Receiver processing... Generating ACKs...
Acknowledgement for Frame 40 received.
Acknowledgement for Frame 50 received.
Acknowledgement for Frame 60 received.
--> Window slides forward.

Sender transmits frames: 70 
Receiver processing... Generating ACKs...
Acknowledgement for Frame 70 received.

--- All frames transmitted successfully! ---


...Program finished with exit code 0
Press ENTER to exit console.
_________________________________________________________




