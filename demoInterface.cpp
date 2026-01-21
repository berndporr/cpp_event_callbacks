#include <stdio.h>
#include "KeypressPublisherInterface.h"
#include <unistd.h>

struct KeypressSubscriber : KeypressPublisherInterface::CallbackInterface {
    void hasEvent() override {
	fprintf(stdout,"Buh! ");
	fflush(stdout);
    }
};

int main( int, const char**) {
	KeypressPublisherInterface keypressPublisher;
	KeypressSubscriber keypressSubscriber;
	keypressPublisher.registerEventCallback(&keypressSubscriber);
	keypressPublisher.start();

	printf("Press return to trigger an event.\n");

	// do nothing. All done in the publisher.
	while (true) {
	    std::this_thread::sleep_for(std::chrono::seconds(60));
	}

	printf("\nAll done.\n");
}
