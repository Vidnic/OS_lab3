#include "marker.h"
#include <iostream>

DWORD WINAPI MarkerThread(LPVOID lpParam) {
    ThreadData* data = static_cast<ThreadData*>(lpParam);

    WaitForSingleObject(data->startEvent, INFINITE);

    srand(data->id);
    int markedCount = 0;

    while (true) {
        int index = rand() % data->size;

        if (data->array[index] == 0) {
            Sleep(5);
            data->array[index] = data->id;
            markedCount++;
            Sleep(5);
        } else {
            std::cout << "Thread #" << data->id
                      << " marked: " << markedCount
                      << " cannot mark index: " << index << std::endl;

            SetEvent(data->cannotContinueEvent);

            HANDLE events[2] = { data->continueEvent, data->stopEvent };
            DWORD res = WaitForMultipleObjects(2, events, FALSE, INFINITE);

            if (res == WAIT_OBJECT_0 + 1) {
                for (int i = 0; i < data->size; i++) {
                    if (data->array[i] == data->id) {
                        data->array[i] = 0;
                    }
                }
                return 0;
            } else {
                ResetEvent(data->continueEvent);
            }
        }
    }
}