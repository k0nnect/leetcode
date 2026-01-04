impl Solution {
    pub fn sum_four_divisors(nums: Vec<i32>) -> i32 {
        let mut total_sum = 0;

        for &num in &nums {
            let mut divisors = Vec::new();
            let mut i = 1;
            
            while i * i <= num {
                if num % i == 0 {
                    divisors.push(i);
                    if i * i != num {
                        divisors.push(num / i);
                    }
                }

                if divisors.len() > 4 {
                    break;
                }
                i += 1;
            }

            if divisors.len() == 4 {
                let sum: i32 = divisors.iter().sum();
                total_sum += sum;
            }
        }

        total_sum
    }
}