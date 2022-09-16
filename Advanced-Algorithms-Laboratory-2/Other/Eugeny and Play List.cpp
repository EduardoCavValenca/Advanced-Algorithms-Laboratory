#include <bits/stdc++.h>
using namespace std;

int main() {

    int num_musics, num_moments;

    cin >> num_musics >> num_moments;

    vector<long long> current_music(num_musics);

    long long start_time = 0;
    for(int i = 0; i < num_musics; i++){

        int quantity, music_duration;
        cin >> quantity >> music_duration;

        start_time += quantity * music_duration;
        current_music[i] = start_time;
    }

    int current_music_index = 0;

    for(int i = 0; i < num_moments; i++){

        int moment;
        cin >> moment;

        while(current_music[current_music_index] < moment)
            current_music_index++;

        cout << current_music_index + 1 << endl;
    }
}