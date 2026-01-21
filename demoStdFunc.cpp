#include <stdio.h>
#include "KeypressPublisherStdFunc.h"
#include <unistd.h>

class KeypressSubscriberStdFunc {
public:
    void keyevent() {
	fprintf(stdout,"Buh! ");
	fflush(stdout);
    }
};

int main( int, const char**) {
	KeypressPublisherStdFunc keypressPublisher;
	KeypressSubscriberStdFunc keypressSubscriber;
	keypressPublisher.registerEventCallback(
	    [&](){keypressSubscriber.keyevent();}
	    );

	keypressPublisher.start();

	printf("Press return to trigger an event.\n");

	// do nothing. All done in the publisher.
	while (true) {
	    std::this_thread::sleep_for(std::chrono::seconds(60));
	}

	printf("\nAll done.\n");
}
