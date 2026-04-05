#include <windows.h>
#include <iostream>
#include "marker.h"

void PrintArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    try {
        int size;
        std::cout << "Array size: ";
        std::cin >> size;

        if (size <= 0) {
            throw std::runtime_error("Invalid size");
        }

        int* array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = 0;
        }

        int threadCount;
        std::cout << "Thread count: ";
        std::cin >> threadCount;

        HANDLE* threads = new HANDLE[threadCount];
        ThreadData* data = new ThreadData[threadCount];
        HANDLE* cannotContinueEvents = new HANDLE[threadCount];

        HANDLE startEvent = CreateEvent(nullptr, TRUE, FALSE, nullptr);

        for (int i = 0; i < threadCount; i++) {
            data[i].id = i + 1;
            data[i].array = array;
            data[i].size = size;

            data[i].startEvent = startEvent;
            data[i].continueEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
            data[i].stopEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
            data[i].cannotContinueEvent = CreateEvent(nullptr, TRUE, FALSE, nullptr);

            cannotContinueEvents[i] = data[i].cannotContinueEvent;

            threads[i] = CreateThread(
                nullptr,
                0,
                MarkerThread,
                &data[i],
                0,
                nullptr
            );

            if (!threads[i]) {
                std::cout << "CreateThread error: " << GetLastError() << std::endl;
                return 1;
            }
        }

        // старт всех потоков
        SetEvent(startEvent);

        int activeThreads = threadCount;

        while (activeThreads > 0) {
            WaitForMultipleObjects(activeThreads, cannotContinueEvents, TRUE, INFINITE);

            PrintArray(array, size);

            int id;
            std::cout << "Stop thread id: ";
            std::cin >> id;

            if (id < 1 || id > activeThreads) {
                std::cout << "Invalid id\n";
                continue;
            }

            SetEvent(data[id - 1].stopEvent);

            WaitForSingleObject(threads[id - 1], INFINITE);

            PrintArray(array, size);

            CloseHandle(threads[id - 1]);

            // сдвиг массивов
            for (int i = id - 1; i < activeThreads - 1; i++) {
                data[i] = data[i + 1];
                threads[i] = threads[i + 1];
                cannotContinueEvents[i] = cannotContinueEvents[i + 1];
            }

            activeThreads--;

            for (int i = 0; i < activeThreads; i++) {
                ResetEvent(data[i].cannotContinueEvent);
                SetEvent(data[i].continueEvent);
            }
        }

        CloseHandle(startEvent);

        delete[] array;
        delete[] threads;
        delete[] data;
        delete[] cannotContinueEvents;
    }
    catch (const std::exception& ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }

    return 0;
}