
use std::cmp::Ordering;

fn main() {
	let coins: [i32; 8] = [1, 2, 5, 10, 20, 50, 100, 200];

    println!("Ways to get 200p: {}", build_coin_sum(200, &coins[..]))
}

/*
 	build_coin_sum
 	 This is a recursive function that will find all possible ways to get
 	 to a specific coin value from smaller denomination coins. It has 3
 	 base cases:
 	  a) total == 0 -> this case means it was able to exactly subtract
 	  					coin values from the total, meaning it was a 
 	  					successful operation. Return '1' to represent
 	  					that the specific method worked.
	  b) total < 0 -> this case means it went too far below, and thus did
	  					not find an exact sum. Return '0'.
	  c) coins.len() == 0 && total > 0 -> this case means there are no
	  										more coin options and still
	  										more of the sum. Impossible
	  										to calculate, return '0'.
	If none of these cases are met, return the sum of the following:
		a) the same total, excluding the last coin in the list of coin
			denominations, and
		b) the total minus the last coin in the list of coin denominations
*/
fn build_coin_sum(total: i32, coins: &[i32]) -> i32 {
	match total.cmp(&0) {
		Ordering::Equal => 1,
		Ordering::Less => 0,
		Ordering::Greater => {
			if coins.len() == 0 { return 0; }
			
			let last = coins.len() - 1;
			build_coin_sum(total, &coins[..last]) + build_coin_sum(total - coins[last], coins)
		}
	}


	
}