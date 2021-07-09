using namespace std;

class Solution {
public:
    int rand10() {
        while(true) {
            int gen = (rand7() - 1) * 7 + rand7(); // Got rand49()
            if(gen <= 40)
                return gen % 10 + 1;
            gen = (gen - 40 - 1) * 7 + rand7(); // Got rand63()
            if(gen <= 60)
                return gen % 10 + 1;
            gen = (gen - 60 - 1) * 7 + rand7(); // Got rand21()
            if(gen <= 20)
                return gen % 10 + 1;
        }
    }
};
