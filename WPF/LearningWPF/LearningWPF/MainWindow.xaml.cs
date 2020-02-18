using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace LearningWPF
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public Person PersonObject { get; set; }
        
        public MainWindow()
        {
            InitializeComponent();
            //PersonObject = new Person()
            //{
            //    Name = "Rishabh Sharma"
            //};
            //PersonObject = new Person()
            //{
            //    FirstName = "Rishabh",
            //    LastName = "Sharma"
            //};
            //this.DataContext = PersonObject;
            this.DataContext = new ViewModel();
        }

        
        //private void Button_Click(object sender, RoutedEventArgs e)
        //{
        //    this.Resources["DynamicColor"] = new SolidColorBrush(Colors.Red);
        //}

        //private void Button_Click_1(object sender, RoutedEventArgs e)
        //{
        //    this.Resources["DynamicColor"] = new SolidColorBrush(Colors.Blue);
        //}



        //public int MyProperty
        //{
        //    get { return (int)GetValue(MyPropertyProperty); }
        //    set { SetValue(MyPropertyProperty, value); }
        //}

        //// Using a DependencyProperty as the backing store for MyProperty.  This enables animation, styling, binding, etc...
        //public static readonly DependencyProperty MyPropertyProperty =
        //    DependencyProperty.Register("MyProperty", typeof(int), typeof(ownerclass), new PropertyMetadata(0));


    }
}
