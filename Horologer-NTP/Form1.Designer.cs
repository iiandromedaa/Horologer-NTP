namespace Horologer_NTP
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.time = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.accuracyMS = new System.Windows.Forms.Label();
            this.lagMS = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // time
            // 
            this.time.AutoSize = true;
            this.time.BackColor = System.Drawing.Color.Black;
            this.time.Font = new System.Drawing.Font("alarm clock", 36F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.time.ForeColor = System.Drawing.Color.Lime;
            this.time.Location = new System.Drawing.Point(111, 82);
            this.time.Name = "time";
            this.time.Size = new System.Drawing.Size(300, 50);
            this.time.TabIndex = 0;
            this.time.Text = "12:00:00 AM";
            this.time.Click += new System.EventHandler(this.time_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(213, 56);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(107, 15);
            this.label2.TabIndex = 1;
            this.label2.Text = "Current Local Time";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(349, 204);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(73, 15);
            this.label1.TabIndex = 2;
            this.label1.Text = "NTP Latency";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(111, 204);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(95, 15);
            this.label3.TabIndex = 3;
            this.label3.Text = "Accuracy to NTP";
            // 
            // accuracyMS
            // 
            this.accuracyMS.AutoSize = true;
            this.accuracyMS.Location = new System.Drawing.Point(134, 230);
            this.accuracyMS.Name = "accuracyMS";
            this.accuracyMS.Size = new System.Drawing.Size(41, 15);
            this.accuracyMS.TabIndex = 4;
            this.accuracyMS.Text = "0.0 ms";
            // 
            // lagMS
            // 
            this.lagMS.AutoSize = true;
            this.lagMS.Location = new System.Drawing.Point(361, 230);
            this.lagMS.Name = "lagMS";
            this.lagMS.Size = new System.Drawing.Size(41, 15);
            this.lagMS.TabIndex = 5;
            this.lagMS.Text = "0.0 ms";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(532, 391);
            this.Controls.Add(this.lagMS);
            this.Controls.Add(this.accuracyMS);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.time);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Label time;
        private Label label2;
        private Label label1;
        private Label label3;
        private Label accuracyMS;
        private Label lagMS;
    }
}