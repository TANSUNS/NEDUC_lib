#ifndef SCALAR_KALMAN_H
#define SCALAR_KALMAN_H

/**
 * 	x = A*x + w; w~N(0,Q)
 * 	y = C*x + v; v~N(0,R)
 */
typedef struct scalar_kalman_s
{
	float A, C;
	float A2, C2; 	// A,C 的平方

	float Q, R;
	float K, P;

	float x;
}scalar_kalman_t;

void scalar_kalman_init(scalar_kalman_t *kalman, float A, float C, float Q, float R);
float scalar_kalman(scalar_kalman_t *kalman, float y);

#endif