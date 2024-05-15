//5223600002 / Bernadus Hendry Haryuwardhana

int Queue::remove() {
    if (Empty()) {
        throw std::runtime_error("QueueEmptyException");
    }
    int value = head->Value;
    head = head->Next;
    count--;
    return value;
}
