class Router {
public:
    typedef struct Packet{
        int src, des, tsmp;

        bool operator<(const Packet& other) const {
            return tie(src, des, tsmp) < tie(other.src, other.des, other.tsmp);
        }
    }Packet;

    int memoryLimit;
    set<Packet> uniquePacket;
    queue<Packet> packetQueue;
    map<int, vector<int>> desTimestamp;
    map<int, int> desTimestampIdx;
    
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        const Packet packet{source, destination, timestamp};
        if(uniquePacket.find(packet) != uniquePacket.end()) {
            return false;
        }
        if(packetQueue.size() == memoryLimit) {
            forwardPacket();
        }

        uniquePacket.insert(packet);
        desTimestamp[destination].push_back(timestamp);
        packetQueue.push(packet);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(packetQueue.empty()) {
            return {};
        }

        const Packet popped = packetQueue.front();
        packetQueue.pop();

        uniquePacket.erase(popped);
        desTimestampIdx[popped.des]++;
        return {popped.src, popped.des, popped.tsmp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(desTimestamp.find(destination) == desTimestamp.end()) {
            return 0;
        }
        const vector<int>& timestamp = desTimestamp[destination];
        int startIdx = desTimestampIdx[destination];

        auto lower = lower_bound(timestamp.begin() + startIdx, timestamp.end(), startTime);
        auto upper = upper_bound(timestamp.begin() + startIdx, timestamp.end(), endTime);

        return upper - lower;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */