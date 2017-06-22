/**
 * @brief Bit size of any R, G or B color inside hwlib::color.
 * @details
 * When pwm_color_bit_size == 2, hwlib::color is downscaled to work with the specified bit size for rgb_matrix
 * Normally hwlib::color works with 8 bit colors, but due to the limitiations of the Arduino Due, it had to be downscaled in order to prevent inconventient flickering.
 */
const int pwm_color_bit_size = 2;
/**
 * @brief Max value of any R, G or B color inside hwlib::color.
 * @details
 * The value is directly correlated with pwm_color_bit_size. It should be exacly 2^pwm_color_bit_size. (For some reason 2^2 resulted in 0, so this way is used)
 */

const int pwm_color_max_value = 4;