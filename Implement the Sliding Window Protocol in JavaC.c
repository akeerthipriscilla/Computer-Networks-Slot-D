#include <stdio.h>

int main() {
    int window_size, total_frames;
    int frames[100];
    int ack_received = 0;

    // 1. Get input parameters from user
    printf("Enter the sliding window size: ");
    scanf("%d", &window_size);

    printf("Enter total number of frames to transmit: ");
    scanf("%d", &total_frames);

    printf("Enter the values/sequence numbers for %d frames:\n", total_frames);
    for (int i = 0; i < total_frames; i++) {
        scanf("%d", &frames[i]);
    }

    printf("\n--- Starting Sliding Window Protocol Simulation ---\n\n");

    // 2. Loop through frames simulating the sliding window
    int i = 0; 
    while (i < total_frames) {
        int frames_in_window = 0;

        // Sender transmits frames within the current window boundary
        printf("Sender transmits frames: ");
        for (int j = i; j < i + window_size && j < total_frames; j++) {
            printf("%d ", frames[j]);
            frames_in_window++;
        }
        printf("\n");

        // Simulate receiver sending back acknowledgements
        printf("Receiver processing... Generating ACKs...\n");
        for (int j = i; j < i + frames_in_window; j++) {
            printf("Acknowledgement for Frame %d received.\n", frames[j]);
        }

        // Slide the window ahead by the number of acknowledged frames
        i += frames_in_window;
        
        if (i < total_frames) {
            printf("--> Window slides forward.\n\n");
        } else {
            printf("\n--- All frames transmitted successfully! ---\n");
        }
    }

    return 0;
}