
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int days[] = {31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};

        string alice_a_hour = "";
        string alice_l_hour = "";
        string bob_a_hour = "";
        string bob_l_hour = "";

        // Alice arrival
        int i = 0;
        while (arriveAlice[i] != '-') {
            alice_a_hour += arriveAlice[i++];
        }

        int alice_arrival_hour = stoi(alice_a_hour);
        alice_a_hour = "";

        i++; 
        while (i < arriveAlice.size()) {
            alice_a_hour += arriveAlice[i++];
        }

        int alice_arrival_min = stoi(alice_a_hour);
        alice_a_hour = "";

        // Alice leaving
        int k = 0;
        while (leaveAlice[k] != '-') {
            alice_l_hour += leaveAlice[k++];
        }

        int alice_leave_hour = stoi(alice_l_hour);
        alice_l_hour = "";

        k++; 
        while (k < leaveAlice.size()) {
            alice_l_hour += leaveAlice[k++];
        }

        int alice_l_min = stoi(alice_l_hour);
        alice_l_hour = "";

        // Bob arrival
        int l = 0;
        while (arriveBob[l] != '-') {
            bob_a_hour += arriveBob[l++];
        }

        int bob_arrival_hour = stoi(bob_a_hour);
        bob_a_hour = "";

        l++; 
        while (l < arriveBob.size()) {
            bob_a_hour += arriveBob[l++];
        }

        int bob_arrival_min = stoi(bob_a_hour);
        bob_a_hour = "";

        // Bob leaving
        int q = 0;
        while (leaveBob[q] != '-') {
            bob_l_hour += leaveBob[q++];
        }

        int bob_leave_hour = stoi(bob_l_hour);
        bob_l_hour = "";

        q++; 
        while (q < leaveBob.size()) {
            bob_l_hour += leaveBob[q++];
        }

        int bob_leave_min = stoi(bob_l_hour);
        bob_l_hour = "";

        int aliceArrival = alice_arrival_min;
        for (int x = 0; x < alice_arrival_hour - 1; x++) {
            aliceArrival += days[x];
        }

        int aliceLeave = alice_l_min;
        for (int x = 0; x < alice_leave_hour - 1; x++) {
            aliceLeave += days[x];
        }

        int bobArrival = bob_arrival_min;
        for (int x = 0; x < bob_arrival_hour - 1; x++) {
            bobArrival += days[x];
        }

        int bobLeave = bob_leave_min;
        for (int x = 0; x < bob_leave_hour - 1; x++) {
            bobLeave += days[x];
        }

        int start = max(aliceArrival, bobArrival);
        int end = min(aliceLeave, bobLeave);

        if (start > end) {
            return 0;
        }

        return end - start + 1;
    }
};
