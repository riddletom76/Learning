using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Configuration;
using OdeToFood.Data;

namespace OdeToFood.Pages.Restaurants
{
    public class ListModel : PageModel
    {
        public string LocalMessage { get; set; }
        public string AppSettingsMessage { get; set; }
        public IConfiguration config { get; }
        public IRestaurantData RestaurantData { get; }
        public IEnumerable<Core.Restaurants> Restaurants;
        [BindProperty(SupportsGet = true)]
        public string SearchTerm { get; set; }
        public ListModel(IConfiguration config, IRestaurantData restaurantData)
        {
            this.config = config;
            this.RestaurantData = restaurantData;
        }
        public void OnGet()
        {
            LocalMessage = "Hello World!";
            AppSettingsMessage = config["Message"];
            Restaurants = RestaurantData.GetRestaurantsByName(SearchTerm);
        }
    }
}
