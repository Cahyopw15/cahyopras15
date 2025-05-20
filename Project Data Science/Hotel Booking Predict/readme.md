# 🏨 Hotel Booking Predict

Proyek ini bertujuan untuk memprediksi pembatalan pemesanan hotel menggunakan pendekatan Data Science. Dengan menganalisis data pemesanan, karakteristik pelanggan, dan faktor lainnya, model prediktif dibangun untuk membantu hotel memahami pola perilaku pelanggan dan mengurangi pembatalan.

## 📌 Link Penting

- 📓 Notebook Proyek: [Hotel Booking Predict](#)
- 📊 Dataset: [Download Dataset](https://drive.google.com/file/d/1j0aV5LzB-3iBA__85rGNa_qZUwkLfMh4/view?usp=sharing)

---

## 🎯 Project Goals

- Mengembangkan model prediksi pembatalan pemesanan hotel.
- Mengidentifikasi faktor-faktor penting yang berkontribusi terhadap pembatalan.
- Meningkatkan efisiensi operasional dan kepuasan pelanggan.

---

## 🧹 Data Cleaning

- Kolom **company** dihapus karena missing values > 90%.
- Kolom **agent** diisi dengan median karena distribusinya normal tanpa outlier.
- Kolom **country** diisi dengan modus (mode).
- Kolom **children** dikonversi ke tipe data integer.
- Kolom **reservation_status_date** dikonversi ke datetime.
- Encoding dilakukan untuk data kategorikal.

---

## 📊 Exploratory Data Analysis (EDA)

- **63.05%** pemesanan tidak dibatalkan, **36.95%** dibatalkan.
- Rata-rata lama menginap: **3-3.5 malam** per hotel.
- Kanal pemasaran paling efektif: **Online TA**.
- Bulan pemesanan tertinggi: **Agustus**, **Juli**, dan **Mei**.
- **Tipe pelanggan:** Transient memiliki tingkat pembatalan tertinggi.

---

## 🛠 Feature Engineering

Fitur baru yang dibuat:
- `total_night`
- `total_guests`
- `lead_time_category`
- `revenue_per_stay`
- `is_mismatched_room`

**Feature selection** menggunakan VIF dan korelasi, fitur dengan VIF tinggi (>5) dihapus atau digabung.

---

## 🤖 Machine Learning

- **Scaling** dan **SMOTE** untuk menangani data tidak seimbang.
- Data dibagi menjadi training (70%) dan testing (30%).
- Model yang digunakan:
  - Logistic Regression
  - Decision Tree
  - KNN
  - XGBoost
  - Random Forest (baseline)

---

## 📈 Evaluation

- **Random Forest** menghasilkan skor F1 tertinggi: **0.897**
- **XGBoost** memberikan alternatif yang solid dengan F1-Score: **0.8969**
- Recall terbaik juga dipegang oleh Random Forest dan XGBoost.
- Fitur paling penting: `deposit_type`, `is_mismatched_room`, dan `required_car_parking_spaces`.

---

## ✅ Recommendation

- Gunakan **Random Forest** untuk performa terbaik secara keseluruhan.
- Gunakan **XGBoost** bila fokus utama adalah mengurangi false positive.
- Analisis lebih lanjut terhadap fitur penting direkomendasikan untuk pengambilan keputusan bisnis hotel.

---

## 👤 Author

**Cahyo Prasetiyo Wibowo**

---

## 🙏 Terima Kasih!


