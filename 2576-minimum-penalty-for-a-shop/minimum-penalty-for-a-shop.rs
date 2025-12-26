impl Solution {
    pub fn best_closing_time(customers: String) -> i32 {
        let bytes = customers.as_bytes();
        let n = bytes.len();

        let mut penalty = bytes.iter().filter(|&&c| c == b'Y').count() as i32;
        let mut min_penalty = penalty;
        let mut best_hour = 0;

        for i in 0..n {
            if bytes[i] == b'Y' {
                penalty -= 1;
            } else {
                penalty += 1;
            }

            if penalty < min_penalty {
                min_penalty = penalty;
                best_hour = (i + 1) as i32;
            }
        }

        best_hour
    }
}