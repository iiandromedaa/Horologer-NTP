using static Horologer_NTP.AboutBox1;

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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.alarmsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.setAlarmsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.settingsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // time
            // 
            this.time.AutoSize = true;
            this.time.BackColor = System.Drawing.Color.Black;
            this.time.Font = new System.Drawing.Font("Consolas", 36F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.time.ForeColor = System.Drawing.Color.Lime;
            this.time.Location = new System.Drawing.Point(114, 85);
            this.time.Name = "time";
            this.time.Size = new System.Drawing.Size(310, 56);
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
            this.label1.Location = new System.Drawing.Point(348, 196);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(73, 15);
            this.label1.TabIndex = 2;
            this.label1.Text = "NTP Latency";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(115, 196);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(95, 15);
            this.label3.TabIndex = 3;
            this.label3.Text = "Accuracy to NTP";
            // 
            // accuracyMS
            // 
            this.accuracyMS.AutoSize = true;
            this.accuracyMS.BackColor = System.Drawing.Color.Black;
            this.accuracyMS.ForeColor = System.Drawing.Color.Lime;
            this.accuracyMS.Location = new System.Drawing.Point(139, 218);
            this.accuracyMS.Name = "accuracyMS";
            this.accuracyMS.Size = new System.Drawing.Size(41, 15);
            this.accuracyMS.TabIndex = 4;
            this.accuracyMS.Text = "0.0 ms";
            // 
            // lagMS
            // 
            this.lagMS.AutoSize = true;
            this.lagMS.BackColor = System.Drawing.Color.Black;
            this.lagMS.ForeColor = System.Drawing.Color.Lime;
            this.lagMS.Location = new System.Drawing.Point(366, 218);
            this.lagMS.Name = "lagMS";
            this.lagMS.Size = new System.Drawing.Size(41, 15);
            this.lagMS.TabIndex = 5;
            this.lagMS.Text = "0.0 ms";
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.alarmsToolStripMenuItem,
            this.settingsToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Padding = new System.Windows.Forms.Padding(5, 2, 0, 2);
            this.menuStrip1.Size = new System.Drawing.Size(542, 24);
            this.menuStrip1.TabIndex = 6;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // alarmsToolStripMenuItem
            // 
            this.alarmsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.setAlarmsToolStripMenuItem});
            this.alarmsToolStripMenuItem.Name = "alarmsToolStripMenuItem";
            this.alarmsToolStripMenuItem.Size = new System.Drawing.Size(56, 20);
            this.alarmsToolStripMenuItem.Text = "Alarms";
            // 
            // setAlarmsToolStripMenuItem
            // 
            this.setAlarmsToolStripMenuItem.Name = "setAlarmsToolStripMenuItem";
            this.setAlarmsToolStripMenuItem.Size = new System.Drawing.Size(130, 22);
            this.setAlarmsToolStripMenuItem.Text = "Set Alarms";
            // 
            // settingsToolStripMenuItem
            // 
            this.settingsToolStripMenuItem.Name = "settingsToolStripMenuItem";
            this.settingsToolStripMenuItem.Size = new System.Drawing.Size(61, 20);
            this.settingsToolStripMenuItem.Text = "Settings";
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aboutToolStripMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.helpToolStripMenuItem.Text = "Help";
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(107, 22);
            this.aboutToolStripMenuItem.Text = "About";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(542, 280);
            this.Controls.Add(this.lagMS);
            this.Controls.Add(this.accuracyMS);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.time);
            this.Controls.Add(this.menuStrip1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuStrip1;
            this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.Name = "Form1";
            this.Text = "Horologer NTP";
            this.Shown += new System.EventHandler(this.Form1_Shown);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
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
        private MenuStrip menuStrip1;
        private ToolStripMenuItem alarmsToolStripMenuItem;
        private ToolStripMenuItem settingsToolStripMenuItem;
        private ToolStripMenuItem helpToolStripMenuItem;
        private ToolStripMenuItem aboutToolStripMenuItem;
        private ToolStripMenuItem setAlarmsToolStripMenuItem;
    }
}