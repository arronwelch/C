/* Review Questions */

// What portable types might you use to get a 32-bit signed integer, and what would the 
// rationale be for each choice?

// To get exactly 32 bits, you could use int32_t, provided it was defined for your system.
// To get the smallest type that could store at least 32 bits, use int_least32_t. And to get
// the type that would provide the fastest computations for 32 bits, choose int_fast32_t.
