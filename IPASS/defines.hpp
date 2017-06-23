/**
 * @brief Downscale divisor for R, G and B when writing colors to rgb_matrix
 * @details
 * When pwm_color_downscale_factor == 64, hwlib::color is downscaled to work with the specified bit size for rgb_matrix
 * Normally hwlib::color works with 8 bit colors, but due to the limitiations of the Arduino Due, it had to be downscaled in order to prevent inconventient flickering.
 * The formula to calculate the downscale is (2^bits_to_downscale_from / 2^bits_to_downscale_to)
 * "bits_to_downscale_from" should be 8
 * "bits_to_downscale_to"  is 2 in this case
 * (2^8 / 2^2) = 64
 */
const int pwm_color_downscale_divisor = 64;

/**
 * @brief Max value of any R, G or B color inside hwlib::color.
 * @details
 * The value is directly correlated with pwm_color_bit_size. It should be exacly 2^pwm_color_bit_size. (For some reason 2^2 resulted in 0, so this way is used)
 */
const int pwm_color_max_value = 4;