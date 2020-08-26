use std::collections::HashSet;
use itertools::Itertools;

fn main() {
    let mut pandigitals: HashSet<u64> = HashSet::new();
    
    let digit_perms = (1..=9).permutations(9);
    // the slice possibilities must have a product which has the proper amount of digits. This leaves with the following options:
    // 1|2345|6789
    // 12|345|6789
    // 123|45|6789
    // 1234|5|6789
    let slice_possibilities: [(usize, usize); 4] = [(0,4), (1,4), (2,4), (3,4)];
    
    for perm in digit_perms {
    	for slice_p in slice_possibilities.iter() {
    		// 123456789
    		let a_slice = &perm[0..slice_p.0+1];
    		let b_slice = &perm[slice_p.0+1..slice_p.1+1];
    		let prod_slice = &perm[slice_p.1+1..];

    		let a = digit_to_num(&a_slice);
    		let b = digit_to_num(&b_slice);
    		let prod = digit_to_num(&prod_slice);

    		if a * b == prod {
    			pandigitals.insert(prod);
    		}
    	}
    }

    println!("pandigitals: {:?}", pandigitals);
    println!("sum of pandigitals: {}", pandigitals.iter().sum::<u64>());

}

fn digit_to_num(dgts: &[usize]) -> u64 {
	let mut num: u64 = 0;

	let mut pow = 1;

	for dig in dgts.iter().rev() {
		num += (*dig as u64) * pow;
		pow *= 10;
	}

	num
}
