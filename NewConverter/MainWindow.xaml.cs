using ManagedLayer;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Forms;
using System.Windows.Input;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.IO;


namespace NewConverter
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private string SrcFileName;

        public MainWindow()
        {
            InitializeComponent();
        }
        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            OpenFileDialog fileDialog = new OpenFileDialog();
            if (fileDialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                foreach (string filename in fileDialog.FileNames)
                {
                    txtSource.Text = filename; // lbFiles.Items.Add(Path.GetFileName(filename));  
                     SrcFileName = System.IO.Path.GetFileName(filename);
                    
                }
            }
        }


        private void Button_Click(object sender, RoutedEventArgs e)
        {
            var _source =txtSource.Text;
            var _destination = txtDestination.Text;
           
            string source = _source.ToString();
            string destin = _destination.ToString();

            ToConvert tc = new ToConvert();
            bool done = tc.Converting(source, destin);
            if (done)
            {
                System.Windows.MessageBox.Show("Done!");
                txtSource.Clear();
                txtDestination.Clear();
            }
            else
            {
                System.Windows.MessageBox.Show("Error!");
                txtSource.Clear();
                txtDestination.Clear();
            }
            //ToConvert tc = ManagedLayer.ToConvert:getInstance();

            //FileModel.Instance;
            // FileModel.Instance.OnConvert(source, destin);
            ////Check if the file exists, we will delete it  
            //if (_destination.Exists)
            //    _destination.Delete();
            ////Create a tast to run copy file  
            //Task.Run(() =>
            //{
            //    _source.Copyfile(_destination, x => progressBar.Dispatcher.BeginInvoke(new Action(() => { progressBar.Value = x; lblPercent.Content = x.ToString() + "%"; })));
            //}).GetAwaiter().OnCompleted(() => progressBar.Dispatcher.BeginInvoke(new Action(() => { progressBar.Value = 100; lblPercent.Content = "100%"; System.Windows.MessageBox.Show("You have successfully copied the file !", "Message", MessageBoxButton.OK, MessageBoxImage.Information); })));
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            FolderBrowserDialog folderBrowserDialog = new FolderBrowserDialog();
            folderBrowserDialog.SelectedPath = @"C:\";
            DialogResult result = folderBrowserDialog.ShowDialog();
            if (result == System.Windows.Forms.DialogResult.OK)
            {
                string selectedFolder = folderBrowserDialog.SelectedPath;
                txtDestination.Text = selectedFolder;
            }
        }
    }
}
