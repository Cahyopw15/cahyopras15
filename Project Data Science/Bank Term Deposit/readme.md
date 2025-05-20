# 💼 Bank Term Deposit - Campaign Optimization

This project aims to optimize bank telemarketing campaigns by predicting which customers are most likely to subscribe to term deposits. By using machine learning models, the goal is to reduce marketing costs and increase conversion rates.

## 📌 Important Links

- 📊 Dataset: [Bank Marketing Dataset (Kaggle)](https://www.kaggle.com/datasets/janiobachmann/bank-marketing-dataset)  
- 📓 Notebook: [Colab Notebook](https://colab.research.google.com/drive/1Z1m0jwidLnVKBS71MtqE15vL8R6qzds-?usp=sharing)

---

## 🎯 Project Goals

- Improve the efficiency of marketing campaigns by identifying customer segments most likely to subscribe.
- Build predictive models to support targeted outreach.
- Reduce operational costs from low-conversion contacts.

---

## 🔍 Problem Statement

The bank's telemarketing campaigns have low conversion rates and are resource-intensive. The objective is to develop a predictive tool to identify high-potential customers for term deposit products.

---

## 🧭 Methodology: CRISP-DM Framework

1. **Business Understanding** – Increase campaign effectiveness and reduce wasted outreach.
2. **Data Understanding** – Analyze contact history and customer attributes.
3. **Data Preparation** – Handle missing values and encode categorical variables.
4. **Exploratory Data Analysis (EDA)** – Discover patterns and correlations.
5. **Modeling** – Train and evaluate classification models.
6. **Evaluation** – Select best-performing model based on business context.

---

## 📊 Data Overview

- Rows: 11,162 → reduced to 8,393 after cleaning.
- Features: 17 → 16 after dropping high-missing column `poutcome`.
- No initial missing values, but several columns had `'unknown'` which were converted to `NaN`.

---

## 🧹 Data Preparation

- Removed column `poutcome` (75% unknown).
- Encoded categorical variables using `LabelEncoder`.
- Handled multicollinearity with VIF analysis (no strong multicollinearity found).

---

## 📈 Exploratory Data Analysis (EDA)

- **46.2%** of clients subscribed to term deposits; **53.8%** did not.
- Most contacts done via **cellular (91.4%)**.
- Best months for subscription: **May, July, August**.
- **Duration** of the last contact is the most influential factor:
  - Above average → **81%** chance of subscription
  - Below average → **39.1%** chance of subscription
- Job type insights:
  - **Retired (72%)** and **Students (79%)** have highest subscription rates.
  - **Blue-collar** and **Entrepreneurs** are least likely to subscribe.
- **Older clients with higher balances** are more responsive.

---

## 🤖 Modeling

Dataset split into **80% training** and **20% testing**.

| Model               | Accuracy | F1-Score | Recall | Precision | Train Acc | Test Acc |
|--------------------|----------|----------|--------|-----------|-----------|----------|
| **LGBM Classifier** | 86%      | 84–87%   | 81–90% | 87–85%    | **91%**   | **85%**  |
| XGBoost Classifier  | 86%      | 84–87%   | 82–89% | 86–85%    | 89%       | 85%      |
| Random Forest       | 85%      | 81–85%   | 78–88% | 84–83%    | 85%       | 83%      |
| Logistic Regression | 78%      | 76–80%   | 77–78% | 75–81%    | 77.3%     | 77.9%    |
| Decision Tree       | 80%      | 78–82%   | 78–82% | 72–82%    | 84%       | 80%      |

✅ **Best Model**: LGBM Classifier – high accuracy, F1-score, recall, and precision with minimal overfitting.

---

## 🌟 Feature Importance

Most influential features:
- **Contact duration**
- **Month of contact**
- **Age**
- **Balance**
- **Job type**
- **Previous contact history (pdays)**

Less important features:
- **Default status**
- **Type of contact (cellular/telephone)**
- **Personal loans**

---

## ✅ Recommendations

1. **Train agents** to conduct longer, more persuasive conversations.
2. **Schedule calls** during high-conversion months (May, July, August).
3. **Target specific demographics** – older clients with high balances.
4. **Customize outreach** based on customer job, age, and history.

---

## 👤 Author

**Cahyo Prasetiyo Wibowo**

---

## 🙏 Thank You!

