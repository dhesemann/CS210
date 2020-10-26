/*
 * CustomerAccount.h
 *
 *  Created on: Oct 4, 2020
 *      Author: 1823901_snhu
 */

#ifndef CUSTOMERACCOUNT_H_
#define CUSTOMERACCOUNT_H_

class CustomerAccount {
	public:
		//Create set functions
		void setInitialAmount(double t_initialAmount) {
			m_initialAmount = t_initialAmount;
		}
		void setMonthlyAmount(double t_monthlyAmount) {
			m_monthlyAmount = t_monthlyAmount;
		}
		void setAnnualInterest(double t_annualInterest) {
			m_annualInterest = t_annualInterest;
		}
		void setNumYears(int t_numYears) {
			m_numYears = t_numYears;
		}
		//Declare class functions
		void displayInitialReport();
		void displayFullReport();
	private:
		//Declare class variables
		double m_initialAmount = 0.0;
		double m_monthlyAmount = 0.0;
		double m_annualInterest = 0.0;
		int m_numYears = 0;
};



#endif /* CUSTOMERACCOUNT_H_ */
