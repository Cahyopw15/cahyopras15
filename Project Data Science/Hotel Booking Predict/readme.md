# 🏨 Hotel Booking Cancellation Prediction

This project aims to predict hotel booking cancellations using a data science approach. By analyzing booking details, customer characteristics, and other influencing factors, we build a predictive model to help hotels understand customer behavior patterns and reduce cancellations.

## 📌 Important Links

- 📓 Notebook: [Hotel Booking Predict](#)
- 📊 Dataset: [Download Dataset](https://drive.google.com/file/d/1j0aV5LzB-3iBA__85rGNa_qZUwkLfMh4/view?usp=sharing)

---

## 🎯 Project Goals

- Build a machine learning model to predict booking cancellations.
- Identify key factors contributing to cancellations.
- Improve operational efficiency and customer satisfaction.

---

## 🧹 Data Cleaning

- The **company** column was dropped due to >90% missing values.
- The **agent** column was filled with the median (no outliers).
- The **country** column was filled with the mode.
- The **children** column was converted to integer type.
- The **reservation_status_date** column was converted to datetime.
- Categorical features were encoded.

---

## 📊 Exploratory Data Analysis (EDA)

- **63.05%** of bookings were not canceled, while **36.95%** were canceled.
- Average stay duration per hotel: **3 to 3.5 nights**.
- Most effective marketing channel: **Online TA**.
- Peak booking months: **August**, followed by **July** and **May**.
- **Customer Type Insight**:
  - **Transient**: most bookings, highest cancellations.
  - **Group**: fewer bookings, lower cancellations.

---

## 🛠 Feature Engineering

Created new features:
- `total_night`
- `total_guests`
- `lead_time_category`
- `revenue_per_stay`
- `is_mismatched_room`

**Feature selection** was done using VIF (Variance Inflation Factor) and correlation analysis. Features with VIF > 5 were dropped or merged.

---

## 🤖 Machine Learning

- Numerical features were scaled.
- SMOTE was used to balance the dataset.
- Data split: 70% training, 30% testing.
- Models trained:
  - Logistic Regression
  - Decision Tree
  - K-Nearest Neighbors (KNN)
  - XGBoost
  - Random Forest (baseline)

---

## 📈 Model Evaluation

- **Random Forest** achieved the best F1-Score: **0.897**
- **XGBoost** was a close second with F1-Score: **0.8969**
- Highest recall: Random Forest and XGBoost
- Key features:
  - `deposit_type`
  - `is_mismatched_room`
  - `required_car_parking_spaces`

---

## ✅ Recommendation

- Use **Random Forest** for best overall performance.
- Use **XGBoost** if the goal is to reduce false positives.
- Further analysis of key features is recommended to optimize hotel booking strategies.

---

## 👤 Author

**Cahyo Prasetiyo Wibowo**

---

## 🙏 Thank You!
