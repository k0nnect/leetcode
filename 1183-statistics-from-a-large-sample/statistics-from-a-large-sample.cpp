class Solution {
public:
vector<double> sampleStats(vector<int>& count) {
double minimum = -1.0;
double maximum = 0.0;
double mean = 0.0;
double median = 0.0;
double mode = 0.0;
long long total_sum = 0;
long long num_elements = 0;
int max_freq = 0;
    for (int i = 0; i < 256; ++i) {
        if (count[i] > 0) {
            if (minimum == -1.0) {
                minimum = i;
            }
            maximum = i;
            total_sum += (long long)i * count[i];
            num_elements += count[i];
            if (count[i] > max_freq) {
                max_freq = count[i];
                mode = i;
            }
        }
    }

    if (num_elements > 0) {
        mean = (double)total_sum / num_elements;
    }

    long long median_pos1 = (num_elements + 1) / 2;
    long long median_pos2 = (num_elements % 2 == 0) ? (num_elements / 2) + 1 : -1;
    long long current_count = 0;
    double median1 = -1.0, median2 = -1.0;

    for (int i = 0; i < 256; ++i) {
        long long prev_count = current_count;
        current_count += count[i];
        if (median1 == -1.0 && current_count >= median_pos1) {
            median1 = i;
        }
        if (median2 == -1.0 && median_pos2 != -1 && current_count >= median_pos2) {
            median2 = i;
        }
        if (median1 != -1.0 && (median_pos2 == -1 || median2 != -1.0)) {
            break;
        }
    }

    if (num_elements % 2 == 1) {
        median = median1;
    } else if (num_elements > 0) {
        median = (median1 + median2) / 2.0;
    }

    if (minimum == -1.0) minimum = 0.0;

    return {minimum, maximum, mean, median, mode};
}
};