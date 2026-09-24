#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

// INTERFACE (Pure Virtual Class)
class Sound {
    public:
        // Pure virtual function makes this an interface
        virtual void play() const = 0;
        // VIRTUAL DESTRUCTOR: Crucial to prevent memory leaks when deleting
        virtual ~Sound() {
            std::cout << "[Sound Destructor] Cleaning up base sound data.\n";
        }
};

// INHERITANCE & POLYMORPHISM (Derived Classes)
class MP3Sound : public Sound {
    public:
        void play() const override {
            std::cout << "Playing compressed MP3 audio file stream.\n";
        }
        ~MP3Sound() override {
            std::cout << "[MP3 Destructor] Freeing compresses buffer memomry.\n";
        }
};

// INHERITANCE & POLYMORPHISM (Derived Classes)
class WAVSound : public Sound {
    private:
        int sampleRate = 44100;
    public:
        void play() const override {
            std::cout << "Playing uncompressed raw WAV audio at " << sampleRate << " Hz.\n"; 
        }
        void boostBass() {
            std::cout << "Bass boosted for high-fidelity WAV file!\n";
        }
        ~WAVSound() override {
            std::cout << "[WAV Destructor] Freeing large raw audio buffer memory.\n";
        }
};

// COMPOSITION (The "Has-A" relationship)
class AudioPlayer {
    private:
        // Use pointers to avoid Object Slicing!
        std::vector<Sound *>playList;
    public:
        void addTrack(Sound *sound){
            playList.push_back(sound);
        }
        void palyAll() const {
            std::cout << "\n --- Starting Playlist Playback (Ploymorphism) --- \n";
            for(const auto& track : playList) {
                track->play();
            }
        }
        const std::vector<Sound *>& getPlaylist() const {
            return playList;
        }
        ~AudioPlayer() {
            std::cout << "\n --- Shutting Down Audio Player (Virtual Destructors) --- \n";
            for(auto& track : playList) {
                delete track;
            }
        }
};

int main(void) {

    AudioPlayer player;

    // Automatic upcasting
    player.addTrack(new MP3Sound());
    player.addTrack(new WAVSound());

    // Ploymorphism and Composition 
    player.palyAll();

    std::cout << "\n --- Testing casting operators --- \n";
    Sound* randomTrack = player.getPlaylist()[1];

    // Dynamic cast (Safe Downcasting at Runtime)
    WAVSound* wavTrack = dynamic_cast<WAVSound *>(randomTrack);
    if(wavTrack) {
        std::cout << "[Success] dynamic_cast confirmed this track is a WAV file.\n";
        wavTrack->boostBass();
    } else {
        std::cout << "[Failed] dynamic_cast returned nullptr. Not a WAV file.\n";
    }

    // Static cast (Compile-Time Cast)
    MP3Sound* myMP3 = new MP3Sound();
    Sound* basePtr = static_cast<Sound *>(myMP3);
    std::cout << "[static_cast] Successfully upcasted MP3 pointer to Sound pointer.\n";

    // Const cast (Stripping or adding const)
    const int hardwareVolume = 80;
    int* modifiableVolume = const_cast<int *>(&hardwareVolume);
    std::cout << "[const_cast] Temporary non-const access to volume: " << *modifiableVolume << "\n";

    // Reinterpret cast (Raw Binary Reinterpretation)
    uintptr_t rawAddress = reinterpret_cast<uintptr_t>(randomTrack);
    std::cout << "[reinterpret_cast] Raw memory address of the sound object: 0x" << std::hex << rawAddress << std::dec << "\n";
    delete basePtr;

    return EXIT_SUCCESS;
}
