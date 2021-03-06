#include "uigestionrh.h"
#include "ui_uigestionrh.h"

gestionrh::gestionrh(QWidget *parent):QWidget(parent),ui(new Ui::gestionrh)
{
    int i;
    ui->setupUi(this);
    e=new employee();
    v=new vacation();
    b= new building();
    QPixmap pxxx("C:/Qt/Tools/QtCreator/bin/Hamadi/build-SMTPEmail-Desktop_Qt_5_5_1_MinGW_32bit-Debug/debug/back_ground_global.png");
    QPixmap scaled_pix= pxxx.scaled(ui->Background_grh->width(),ui->Background_grh->height());
    ui->Background_grh->setPixmap(scaled_pix);
    hide_what_needs_to_be_hidden();
    update_table_view();

    on_enable_or_select_new_raise_clicked();// to initialise the function
    on_enable_or_select_new_raise_clicked();// twice to get it back to the main state
    ui->take_me_back_to_search->hide();
    show_me_the_meaning_of_being_lonely();
    ui->employee_list->resizeRowsToContents();
    ui->employee_list->resizeColumnsToContents();
    connect_slots_with_header_signal();
    ui->vac_id_employee->setModel(e->employee_id_list());
    ui->mod_vac_id_employee->setModel(v->employees_id_list_with_vacations());//you need to insert employees that have vacations only ;
    insert_employee_combobox_data();
    insert_raises_combobx_data();
    ui->building->setModel( b->building_id_list());
    ui->mod_building->setModel( b->building_id_list());
    ui->mod_interveiwer->setModel( e->employee_list_by_post("interveiwer"));
    /*-----------inserting dates values for initialisation ------------*/
    QDate date;
    date=QDate::currentDate();
    int limit=date.year()-1970;
    int week=8 ;
    int  currentday= date.dayOfWeek();
    QDate start_date,end_date;
    start_date=date.addDays(currentday-week);
    end_date=start_date.addDays(week);
    start_date=start_date.addDays(7);
    for(i=0;i<50;i++)
    {
        ui->shift_week->insertItem(i,start_date.toString("dd/MM/yyyy"));
        start_date=start_date.addDays(7);
    }







    for(i=1; i<=limit; i++)
    {
        QString year=QString::number(i+1969);
        ui->years_led->insertItem(i,year);
        ui->mod_years_led->insertItem(i,year);
        ui->mod_prom_years_led->insertItem(i,year);
    }
    for(i=1; i<=limit; i++)
    {
        QString year=QString::number(i+date.year()-1);
        ui->vac_start_years->insertItem(i,year);
        ui->vac_end_years->insertItem(i,year);
        ui->mod_vac_start_years->insertItem(i,year);
        ui->mod_vac_end_years->insertItem(i,year);
    }
    limit=date.year()-1937;
    for(i=1; i<=limit; i++)
    {
        QString year=QString::number(i+1919);
        ui->years_b->insertItem(i,year);
        ui->mod_years_b->insertItem(i,year);
    }


    QString dataa="";
    for( i=1; i<=31; i++)
    {
        if(i<=9)
        {
            dataa="0"+QString::number(i);
        }
        else
        {
            dataa=QString::number(i);
        }
        ui->vac_start_days->insertItem(i,dataa);
        ui->vac_end_days->insertItem(i,dataa);
        ui->mod_vac_start_days->insertItem(i,dataa);
        ui->mod_vac_start_days->insertItem(i,dataa);
    }


    /*--------------------------------------------------*/
    insert_employee_data();
    hide_colors();
    hide_graph_titels();
    hide_graph_side_bar();




    delete e;

}
gestionrh::~gestionrh()
{
    delete ui;
}
void  gestionrh::hide_colors()
{
    ui->red->hide();
    ui->blue->hide();
    ui->green->hide();
    ui->yellow->hide();
    ui->black->hide();
    QPixmap mymap("C:/Users/gambler/Desktop/back_ground_global.png");
    this->width();
    this->height();



}
void  gestionrh::hide_what_needs_to_be_hidden()
{
    ui->big_trucks_l->hide();
    ui->small_trucks_l->hide();
    ui->driver_lisence->hide();
    ui->driver_l_ex_d->hide();
    ui->yes_1->hide();
    ui->yes_2->hide();
    ui->driver_lisence->hide();
    ui->driver_serial->hide();
    ui->years_led->hide();
    ui->months_led->hide();
    ui->days_led->hide();
    ui->type->hide();
    ui->e_mail->hide();
    ui->email_l->hide();
    ui->type_l->hide();
    ui->manager_l->hide();
    ui->driver_l->hide();
    ui->manager_up_line->hide();
    ui->driver_up_line->hide();
    ui->driver_nd_manager_line->hide();
    hide_manager_items();
    hide_driver_items();
    ui->lisence_expiration_date_lab->hide();
    ui->big_trucks_lab->hide();
    ui->small_trucks_lab->hide();
    ui->lisenc_serial_lab->hide();
    ui->manager_type_lab->hide();
    ui->email_adress_lab->hide();




}
void  gestionrh::hide_driver_items()
{
    ui->mod_big_trucks_l->hide();
    ui->mod_small_trucks_l->hide();
    ui->mod_driver_lisence->hide();
    ui->mod_years_led->hide();
    ui->mod_months_led->hide();
    ui->mod_days_led->hide();
    ui->mod_driver_l_ex_d->hide();
    ui->mod_driver_l->hide();
    ui->mod_driver_serial->hide();
    ui->mod_driver_up_line->hide();
    ui->mod_driver_nd_manager_line->hide();
    ui->mod_yes_2->hide();
    ui->mod_yes_1->hide();
    ui->mod_big_trucks_lab->hide();
    ui->mod_small_trucks_lab->hide();
    ui->mod_lisence_expiration_date_lab->hide();
    ui->mod_lisenc_serial_lab->hide();


}
void  gestionrh::hide_manager_items()
{
    ui->mod_manager_down_line->hide();
    ui->mod_manager_l->hide();
    ui->mod_manager_up_line->hide();
    ui->mod_driver_nd_manager_line->hide();
    ui->mod_email_l->hide();
    ui->mod_e_mail->hide();
    ui->mod_type->hide();
    ui->mod_type_l->hide();
    ui->mod_manager_left_line->hide();
    ui->mod_email_adress_lab->hide();
    ui->mod_manager_type_lab->hide();
}
void  gestionrh::show_driver_items()
{
    ui->mod_big_trucks_l->show();
    ui->mod_small_trucks_l->show();
    ui->mod_driver_lisence->show();
    ui->mod_years_led->show();
    ui->mod_months_led->show();
    ui->mod_days_led->show();
    ui->mod_driver_l_ex_d->show();
    ui->mod_driver_l->show();
    ui->mod_driver_serial->show();
    ui->mod_driver_up_line->show();
    ui->mod_driver_nd_manager_line->show();
    ui->mod_yes_2->show();
    ui->mod_yes_1->show();
    ui->mod_big_trucks_lab->show();
    ui->mod_small_trucks_lab->show();
    ui->mod_lisence_expiration_date_lab->show();
    ui->mod_lisenc_serial_lab->show();

}
void  gestionrh::show_manager_items()
{
    ui->mod_manager_down_line->show();
    ui->mod_manager_l->show();
    ui->mod_manager_up_line->show();
    ui->mod_driver_nd_manager_line->show();
    ui->mod_email_l->show();
    ui->mod_e_mail->show();
    ui->mod_type->show();
    ui->mod_type_l->show();
    ui->mod_manager_left_line->show();
    ui->mod_email_adress_lab->show();
    ui->mod_manager_type_lab->show();
}
void  gestionrh::on_mod_post_currentIndexChanged()
{
    QString choice=ui->mod_post->currentText();
    if(choice=="manager")

    {
        hide_driver_items();
        show_manager_items();

    }
    if(choice=="driver")
    {
        hide_manager_items();
        show_driver_items();
    }
    if(choice!="manager"&&choice!="driver")
    {
        hide_manager_items();
        hide_driver_items();
    }
}
void  gestionrh::resize_objects()
{
    QRect rec = geometry();//declaring a rectangle variable and assigning the screen geometry to it
    int height=rec.height();//getting height of screen
    int width=rec.width();//getting width of screen
    ui->grh->resize(width,height);//resizing the container to screen size
}
void  gestionrh::manage_mod_birthdate()
{
    int month ;
    int year ;
    inputcontrol p;
    QString dataa;
    month=ui->mod_months_b->currentIndex();
    year=ui->mod_years_b->currentText().toInt();

    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        int pos=ui->mod_days_b->currentIndex();
        int i;
        ui->mod_days_b->clear();
        ui->mod_days_b->insertItem(0,"days");

        for(i=1; i<=31; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->mod_days_b->insertItem(i,dataa);
            if(pos>i)
            {
                ui->mod_days_b->setCurrentIndex(31);
            }
            else
            {
                ui->mod_days_b->setCurrentIndex(pos);
            }
        }
    }
    if(month==2&&p.is_leap_year(year))
    {
        int pos=ui->mod_days_b->currentIndex();
        int i;
        ui->mod_days_b->clear();
        ui->mod_days_b->insertItem(0,"days");

        for( i=1; i<=29; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            };
            ui->mod_days_b->insertItem(i,dataa);
            if(pos>i)
            {
                ui->mod_days_b->setCurrentIndex(29);
            }
            else
            {
                ui->mod_days_b->setCurrentIndex(pos);
            }
        }

    }
    if(month==2&&p.is_leap_year(year)==false)
    {
        int pos=ui->mod_days_b->currentIndex();
        int i;

        ui->mod_days_b->clear();
        ui->mod_days_b->insertItem(0,"days");
        for(i=1; i<=28; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->mod_days_b->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->mod_days_b->setCurrentIndex(28);
        }
        else
        {
            ui->mod_days_b->setCurrentIndex(pos);
        }


    }
    if(month==4||month==6||month==11||month==9)
    {
        int pos=ui->mod_days_b->currentIndex();
        int i;
        ui->mod_days_b->clear();
        ui->mod_days_b->insertItem(0,"days");
        for( i=1; i<=30; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->mod_days_b->insertItem(i,dataa);
            if(pos>i)
            {
                ui->mod_days_b->setCurrentIndex(30);
            }
            else
            {
                ui->mod_days_b->setCurrentIndex(pos);
            }

        }
    }
}
void  gestionrh::manage_mod_lisence_date()
{
    int month ;
    int year ;
    inputcontrol p;
    QString dataa;
    month=ui->months_led->currentIndex();
    year=ui->years_led->currentText().toInt();

    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        int pos=ui->mod_days_led->currentIndex();
        int i;
        ui->mod_days_led->clear();
        ui->mod_days_led->insertItem(0,"days");

        for( i=1; i<=31; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->mod_days_led->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->mod_days_led->setCurrentIndex(31);
        }
        else
        {
            ui->mod_days_led->setCurrentIndex(pos);
        }
    }
    if(month==2&&p.is_leap_year(year))
    {
        int pos=ui->mod_days_led->currentIndex();
        int i;
        ui->mod_days_led->clear();
        ui->mod_days_led->insertItem(0,"days");

        for( i=1; i<=29; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->mod_days_led->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->mod_days_led->setCurrentIndex(29);
        }
        else
        {
            ui->mod_days_led->setCurrentIndex(pos);
        }
    }
    if(month==2&&p.is_leap_year(year)==false)
    {
        int pos=ui->mod_days_led->currentIndex();
        int i;
        ui->mod_days_led->clear();
        ui->mod_days_led->insertItem(0,"days");
        for( i=1; i<=28; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->mod_days_led->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->mod_days_led->setCurrentIndex(28);
        }
        else
        {
            ui->mod_days_led->setCurrentIndex(pos);
        }
    }
    if(month==4||month==6||month==11||month==9)
    {
        int pos=ui->mod_days_led->currentIndex();
        int i;
        ui->mod_days_led->clear();
        ui->mod_days_led->insertItem(0,"days");
        for( i=1; i<=30; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->mod_days_led->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->mod_days_led->setCurrentIndex(30);
        }
        else
        {
            ui->mod_days_led->setCurrentIndex(pos);
        }
    }
}
void  gestionrh::on_disconnection_clicked()
{
    int res= QMessageBox::warning(this,"warning","you requested a session closure \n are you sure ? ! \n ","yes","no");
    if(res==0)
    {
        this->close();
    }
    else
    {
        /* do nothing*/
    }
}
void  gestionrh::set_session(int id,QString pwd)
{
    ide=id;
    this->pass=pwd;
}
void  gestionrh::on_pwd_change_clicked()
{
    pwd=new password(this); //setting the layout
    pwd->load_credentials(ide,pass);
    pwd->show();


}
void  gestionrh::on_post_currentIndexChanged()
{
    QString choice=ui->post->currentText();
    if(choice=="manager")
    {
        ui->type->show();
        ui->e_mail->show();
        ui->email_l->show();
        ui->type_l->show();
        ui->manager_up_line->show();
        ui->driver_nd_manager_line->show();
        ui->manager_type_lab->show();
        ui->email_adress_lab->show();
        ui->manager_l->show();
        ui->big_trucks_l->hide();
        ui->small_trucks_l->hide();
        ui->driver_lisence->hide();
        ui->driver_l_ex_d->hide();
        ui->yes_1->hide();
        ui->small_trucks_lab->hide();
        ui->big_trucks_lab->hide();
        ui->lisenc_serial_lab->hide();
        ui->lisence_expiration_date_lab->hide();
        ui->yes_2->hide();
        ui->driver_lisence->hide();
        ui->driver_serial->hide();
        ui->years_led->hide();
        ui->months_led->hide();
        ui->days_led->hide();
        ui->driver_l->hide();
        ui->driver_up_line->hide();
    }
    if(choice=="driver")
    {
        ui->type->hide();
        ui->e_mail->hide();
        ui->email_l->hide();
        ui->type_l->hide();
        ui->manager_l->hide();
        ui->manager_up_line->hide();
        ui->manager_type_lab->hide();
        ui->email_adress_lab->hide();
        ui->big_trucks_l->show();
        ui->small_trucks_l->show();
        ui->driver_lisence->show();
        ui->driver_l_ex_d->show();
        ui->yes_1->show();
        ui->yes_2->show();
        ui->driver_lisence->show();
        ui->driver_serial->show();
        ui->years_led->show();
        ui->months_led->show();
        ui->days_led->show();
        ui->driver_l->show();
        ui->driver_nd_manager_line->show();
        ui->driver_up_line->show();
        ui->small_trucks_lab->show();
        ui->lisenc_serial_lab->show();
        ui->lisence_expiration_date_lab->show();
        ui->big_trucks_lab->show();
    }
    if(choice!="manager"&&choice!="driver")
    {
        ui->big_trucks_l->hide();
        ui->small_trucks_l->hide();
        ui->driver_lisence->hide();
        ui->driver_l_ex_d->hide();
        ui->yes_1->hide();
        ui->yes_2->hide();
        ui->driver_lisence->hide();
        ui->driver_serial->hide();
        ui->years_led->hide();
        ui->months_led->hide();
        ui->days_led->hide();
        ui->type->hide();
        ui->e_mail->hide();
        ui->email_l->hide();
        ui->type_l->hide();
        ui->manager_up_line->hide();
        ui->driver_up_line->hide();
        ui->driver_nd_manager_line->hide();
        ui->manager_l->hide();
        ui->driver_l->hide();
        ui->lisence_expiration_date_lab->hide();
        ui->big_trucks_lab->hide();
        ui->small_trucks_lab->hide();
        ui->lisenc_serial_lab->hide();
        ui->manager_type_lab->hide();
        ui->email_adress_lab->hide();
    }
}
void  gestionrh::manage_birthdate()
{
    int month ;
    int year ;
    inputcontrol p;
    QString dataa;
    month=ui->months_b->currentIndex();
    year=ui->years_b->currentText().toInt();

    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        int pos=ui->days_b->currentIndex();
        int i;
        ui->days_b->clear();
        ui->days_b->insertItem(0,"days");

        for(i=1; i<=31; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->days_b->insertItem(i,dataa);
            if(pos>i)
            {
                ui->days_b->setCurrentIndex(31);
            }
            else
            {
                ui->days_b->setCurrentIndex(pos);
            }
        }
    }
    if(month==2&&p.is_leap_year(year))
    {
        int pos=ui->days_b->currentIndex();
        int i;
        ui->days_b->clear();
        ui->days_b->insertItem(0,"days");

        for( i=1; i<=29; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            };
            ui->days_b->insertItem(i,dataa);
            if(pos>i)
            {
                ui->days_b->setCurrentIndex(29);
            }
            else
            {
                ui->days_b->setCurrentIndex(pos);
            }
        }

    }
    if(month==2&&p.is_leap_year(year)==false)
    {
        int pos=ui->days_b->currentIndex();
        int i;

        ui->days_b->clear();
        ui->days_b->insertItem(0,"days");
        for(i=1; i<=28; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->days_b->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->days_b->setCurrentIndex(28);
        }
        else
        {
            ui->days_b->setCurrentIndex(pos);
        }


    }
    if(month==4||month==6||month==11||month==9)
    {
        int pos=ui->days_b->currentIndex();
        int i;
        ui->days_b->clear();
        ui->days_b->insertItem(0,"days");
        for( i=1; i<=30; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->days_b->insertItem(i,dataa);
            if(pos>i)
            {
                ui->days_b->setCurrentIndex(30);
            }
            else
            {
                ui->days_b->setCurrentIndex(pos);
            }

        }
    }
}
void  gestionrh::manage_lisence_date()
{
    int month ;
    int year ;
    inputcontrol p;
    QString dataa;
    month=ui->months_led->currentIndex();
    year=ui->years_led->currentText().toInt();

    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        int pos=ui->days_led->currentIndex();
        int i;
        ui->days_led->clear();
        ui->days_led->insertItem(0,"days");

        for( i=1; i<=31; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->days_led->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->days_led->setCurrentIndex(31);
        }
        else
        {
            ui->days_led->setCurrentIndex(pos);
        }
    }
    if(month==2&&p.is_leap_year(year))
    {
        int pos=ui->days_led->currentIndex();
        int i;
        ui->days_led->clear();
        ui->days_led->insertItem(0,"days");

        for( i=1; i<=29; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->days_led->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->days_led->setCurrentIndex(29);
        }
        else
        {
            ui->days_led->setCurrentIndex(pos);
        }
    }
    if(month==2&&p.is_leap_year(year)==false)
    {
        int pos=ui->days_led->currentIndex();
        int i;
        ui->days_led->clear();
        ui->days_led->insertItem(0,"days");
        for( i=1; i<=28; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->days_led->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->days_led->setCurrentIndex(28);
        }
        else
        {
            ui->days_led->setCurrentIndex(pos);
        }
    }
    if(month==4||month==6||month==11||month==9)
    {
        int pos=ui->days_led->currentIndex();
        int i;
        ui->days_led->clear();
        ui->days_led->insertItem(0,"days");
        for( i=1; i<=30; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->days_led->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->days_led->setCurrentIndex(30);
        }
        else
        {
            ui->days_led->setCurrentIndex(pos);
        }
    }
}
void  gestionrh::on_months_b_currentIndexChanged()
{
    manage_birthdate();
}
void  gestionrh::on_years_b_currentIndexChanged()
{
    manage_birthdate();
}
void  gestionrh::on_years_led_currentIndexChanged()
{
    manage_lisence_date();
}
void  gestionrh::on_months_led_currentIndexChanged()
{
    manage_lisence_date();
}
void  gestionrh::on_clear_clicked()
{
    hide_add_alert_labels();

    ui->name->clear();
    ui->family_name->clear();
    ui->phone_n->clear();
    ui->zip_code->clear();
    ui->street->clear();
    ui->area->clear();
    ui->city->clear();
    ui->ssn->clear();
    ui->social_state->setCurrentIndex(0);
    ui->post->setCurrentIndex(0);
    ui->gender->setCurrentIndex(0);
    ui->contract->setCurrentIndex(0);
    ui->paiment->setCurrentIndex(0);
    ui->cv->clear();
    ui->motivation_letter->clear();
    ui->salary->clear();
    ui->yes_1->setChecked(false);
    ui->yes_2->setChecked(false);
    ui->days_b->setCurrentIndex(0);
    ui->days_led->setCurrentIndex(0);
    ui->years_b->setCurrentIndex(0);
    ui->years_led->setCurrentIndex(0);
    ui->months_b->setCurrentIndex(0);
    ui->months_led->setCurrentIndex(0);
    ui->cin->clear();
    ui->pix_map_photo->clear();
}
void  gestionrh::hide_add_alert_labels()
{
    ui->big_trucks_l->hide();
    ui->birthdate_l->hide();
    ui->building_l->hide();
    ui->cvital_l->hide();
    ui->b_salary_l->hide();
    ui->email_l->hide();
    ui->citizenin_l->hide();
    ui->family_name_l->hide();
    ui->name_l->hide();
    ui->type_l->hide();
    ui->type_p_l->hide();
    ui->gender_l->hide();
    ui->driver_serial->hide();
    ui->driver_l_ex_d->hide();
    ui->big_trucks_l->hide();
    ui->small_trucks_l->hide();
    ui->street_l->hide();
    ui->area_l->hide();
    ui->city_l->hide();
    ui->zip_code_l->hide();
    ui->type_c_l->hide();
    ui->type_p_l->hide();
    ui->social_s_l->hide();
    ui->phone_number_l->hide();
    ui->post_l->hide();
    ui->ssnumber_l->hide();
    ui->interveiwer_l->hide();
    ui->letter_l->hide();
}
bool  gestionrh::is_add_data_existant_and_valid()
{

    hide_add_alert_labels();

    int res=0 ;

    QString msg2="unvalid";

    QString space=" ";

    inputcontrol p;

    QString msg="empty field";

    if(ui->name->text().isEmpty())

    {

        ui->name_l->setText(msg);

        ui->name_l->setStyleSheet("QLabel {  color : red; }");

        ui->name_l->show();

        res++;
    }

    else if(p.is_valid_name(ui->name->text())==false)

    {
        ui->name_l->setText(msg2+space+"name");

        ui->name_l->setStyleSheet("QLabel {  color : blue; }");

        ui->name_l->show();

        res++;
    }

    if(ui->family_name->text().isEmpty())

    {
        ui->family_name_l->setText(msg);

        ui->family_name_l->setStyleSheet("QLabel {color : red; }");

        ui->family_name_l->show();

        res++;
    }

    else if(p.is_valid_name(ui->family_name->text())==false)

    {
        ui->family_name_l->setText(msg2+space+"last name");

        ui->family_name_l->setStyleSheet("QLabel {color : blue; }");

        ui->family_name_l->show();

        res++;
    }

    if(ui->ssn->text().isEmpty())

    {
        ui->ssnumber_l->setText(msg);

        ui->ssnumber_l->setStyleSheet("QLabel {color : red; }");

        ui->ssnumber_l->show();

        res++;
    }

    else if(p.is_number(ui->ssn->text())==false)

    {
        ui->ssnumber_l->setText(msg2+space+"s.s number");

        ui->ssnumber_l->setStyleSheet("QLabel {color : blue; }");

        ui->ssnumber_l->show();

        res++;
    }

    if(ui->social_state->currentIndex()==0)

    {
        ui->social_s_l->setText("unspecified social state");

        ui->social_s_l->setStyleSheet("QLabel {color : red; }");

        ui->social_s_l->show();

        res++;
    }

    if(ui->phone_n->text().isEmpty())

    {
        ui->phone_number_l->setText(msg);

        ui->phone_number_l->setStyleSheet("QLabel {color : red; }");

        ui->phone_number_l->show();

        res++;
    }

    else if(p.is_valid_cin_or_phone(ui->phone_n->text())==false)

    {

        ui->phone_number_l->setText(msg2+space+"phone number");

        ui->phone_number_l->setStyleSheet("QLabel {color : blue; }");

        ui->phone_number_l->show();

        res++;
    }

    if(ui->cin->text().isEmpty())

    {
        ui->citizenin_l->setText(msg);

        ui->citizenin_l->setStyleSheet("QLabel {color : red; }");

        ui->citizenin_l->show();

        res++;
    }

    else if(p.is_valid_cin_or_phone(ui->cin->text())==false)

    {
        ui->citizenin_l->setText(msg2+space+"cin");

        ui->citizenin_l->setStyleSheet("QLabel {color : blue; }");

        ui->citizenin_l->show();

        res++;
    }

    if(ui->gender->currentIndex()==0)
    {
        ui->gender_l->setText("unspecified gender");

        ui->gender_l->setStyleSheet("QLabel {color : red; }");

        ui->gender_l->show();

        res++;
    }

    if(ui->post->currentIndex()==0)
    {
        ui->post_l->setText("unspecified post");

        ui->post_l->setStyleSheet("QLabel {color : red; }");

        ui->post_l->show();

        res++;
    }

    if(ui->salary->text().isEmpty())
    {

        ui->b_salary_l->setText(msg);

        ui->b_salary_l->setStyleSheet("QLabel {color : red; }");

        ui->b_salary_l->show();

        res++;
    }

    else if(p.is_valid_float(ui->salary->text())==false)
    {

        ui->b_salary_l->setText(msg2+space+"salary");

        ui->b_salary_l->setStyleSheet("QLabel {color : blue; }");

        ui->b_salary_l->show();

        res++;
    }

    if(ui->contract->currentIndex()==0)

    {

        ui->type_c_l->setText("unspecified contract type");

        ui->type_c_l->setStyleSheet("QLabel {color : red; }");

        ui->type_c_l->show();

        res++;

    }

    if(ui->paiment->currentIndex()==0)

    {
        ui->type_p_l->setText("unspecified paiment type");

        ui->type_p_l->setStyleSheet("QLabel {color : red; }");

        ui->type_p_l->show();

        res++;

    }

    if(ui->cv->text().isEmpty())

    {
        ui->cvital_l->setText(msg);

        ui->cvital_l->setStyleSheet("QLabel {color : red; }");

        ui->cvital_l->show();

        res++;

    }

    if(ui->motivation_letter->text().isEmpty())

    {

        ui->letter_l->setText(msg);

        ui->letter_l->setStyleSheet("QLabel {color : red; }");

        ui->letter_l->show();

        res++;
    }

    if(ui->street->text().isEmpty())

    {

        ui->street_l->setText(msg);

        ui->street_l->setStyleSheet("QLabel {color : red; }");

        ui->street_l->show();

        res++;

    }

    if(ui->city->text().isEmpty())

    {

        ui->city_l->setText(msg);

        ui->city_l->setStyleSheet("QLabel {color : red; }");

        ui->city_l->show();

        res++;

    }

    if(ui->area->text().isEmpty())

    {

        ui->area_l->setText(msg);

        ui->area_l->setStyleSheet("QLabel {color : red; }");

        ui->area_l->show();

        res++;

    }

    if(ui->zip_code->text().isEmpty())

    {

        ui->zip_code_l->setText(msg);

        ui->zip_code_l->setStyleSheet("QLabel {color : red; }");

        ui->zip_code_l->show();

        res++;

    }

    if(ui->days_b->currentIndex()==0)

    {

        ui->birthdate_l->setText("unspecified day");

        ui->birthdate_l->setStyleSheet("QLabel {color : red; }");

        ui->birthdate_l->show();

        res++;

    }

    if(ui->years_b->currentIndex()==0)

    {

        ui->birthdate_l->setText("unspecified year");

        ui->birthdate_l->setStyleSheet("QLabel {color : red; }");

        ui->birthdate_l->show();

        res++;

    }

    if(ui->months_b->currentIndex()==0)

    {

        ui->birthdate_l->setText("unspecified month");

        ui->birthdate_l->setStyleSheet("QLabel {color : red; }");

        ui->birthdate_l->show();

        res++;

    }

    if(ui->months_b->currentIndex()==0&&ui->years_b->currentIndex()==0&&ui->days_b->currentIndex()==0)

    {

        ui->birthdate_l->setText("unspecified birthdate");

        ui->birthdate_l->setStyleSheet("QLabel {color : red; }");

        ui->birthdate_l->show();

        res++;

    }

    if(ui->days_led->currentIndex()==0&&ui->post->currentIndex()==3)

    {

        ui->driver_l_ex_d->setText("unspecified day");

        ui->driver_l_ex_d->setStyleSheet("QLabel {color : red; }");

        ui->driver_l_ex_d->show();

        res++;

    }

    if(ui->years_led->currentIndex()==0&&ui->post->currentIndex()==3)

    {

        ui->driver_l_ex_d->setText("unspecified year");

        ui->driver_l_ex_d->setStyleSheet("QLabel {color : red; }");

        ui->driver_l_ex_d->show();

        res++;

    }

    if(ui->months_led->currentIndex()==0&&ui->post->currentIndex()==3)

    {

        ui->driver_l_ex_d->setText("unspecified month");

        ui->driver_l_ex_d->setStyleSheet("QLabel {color : red; }");

        ui->driver_l_ex_d->show();

        res++;

    }

    if(ui->months_led->currentIndex()==0&&ui->years_led->currentIndex()==0&&ui->days_led->currentIndex()==0&&ui->post->currentIndex()==3)

    {

        ui->driver_l_ex_d->setText("unspecified expiration date");

        ui->driver_l_ex_d->setStyleSheet("QLabel {color : red; }");

        ui->driver_l_ex_d->show();

        res++;

    }

    if(ui->driver_lisence->text().isEmpty()&&ui->post->currentIndex()==3)
    {

        ui->driver_serial->setText(msg);

        ui->driver_serial->setStyleSheet("QLabel {color : red; }");

        ui->driver_serial->show();

        res++;

    }

    if(ui->e_mail->text().isEmpty()&&ui->post->currentIndex()==4)

    {

        ui->email_l->setText(msg);

        ui->email_l->setStyleSheet("QLabel {color : red; }");

        ui->email_l->show();

        res++;

    }

    else if(p.is_valid_email(ui->e_mail->text())==false&&ui->post->currentIndex()==4)

    {

        ui->email_l->setText(msg2+space+"email");

        ui->email_l->setStyleSheet("QLabel {color : blue; }");

        ui->email_l->show();

        res++;

    }

    if(ui->type->currentIndex()==0&&ui->post->currentIndex()==4)

    {

        ui->type_l->setText("unspecified type");

        ui->type_l->setStyleSheet("QLabel {color : red; }");

        ui->type_l->show();

        res++;
    }

    if(res>0)
    {
        return false;
    }

    else
    {
        return true;
    }

}

bool gestionrh::is_promotion_data_existant_and_valid()
{

    hide_promotions_alert_labels();
    int res=0 ;

    QString msg2="unvalid";

    QString space=" ";

    inputcontrol p;

    QString msg="unspecified";

    if(ui->mod_prom_foreign_post_com->currentText()==0)

    {

        ui->mod_prom_new_post_lab->setText(msg+space+"post");

        ui->mod_prom_new_post_lab->setStyleSheet("QLabel {  color : red; }");

        ui->mod_prom_new_post_lab->show();

        res++;
    }
    if(ui->mod_prom_Salary_bonus_sp->text()=="0%")

    {

        ui->mod_prom_salary_alert_lab->setText("salary bonus seems low");

        ui->mod_prom_salary_alert_lab->setStyleSheet("QLabel {  color : blue; }");

        ui->mod_prom_salary_alert_lab->show();

        res++;
    }


    else if(p.is_valid_float(ui->mod_salary_emp_name_le->text())==false)

    {
        ui->name_l->setText(msg2+space+"salary");

        ui->name_l->setStyleSheet("QLabel {  color : blue; }");

        ui->name_l->show();
    }
    if(ui->mod_prom_contract_cb->currentIndex()==0)

    {

        ui->mod_prom_type_c_l->setText(msg+space+"contract type");

        ui->mod_prom_type_c_l->setStyleSheet("QLabel {  color : red; }");

        ui->mod_prom_type_c_l->show();

        res++;
    }
    if(ui->mod_prom_paiment_cb->currentIndex()==0)
    {

        ui->mod_prom_type_p_l->setText(msg+space+"paiment methode");

        ui->mod_prom_type_p_l->setStyleSheet("QLabel {  color : red; }");

        ui->mod_prom_type_p_l->show();

        res++;
    }
    if(ui->mod_prom_foreign_post_com->currentText()=="manager"&&ui->mod_prom_type->currentIndex()==0)
    {

        ui->mod_prom_type_l->setText(msg+space+"manager type");

        ui->mod_prom_type_l->setStyleSheet("QLabel {  color : red; }");

        ui->mod_prom_type_l->show();

        res++;
    }
    if(ui->mod_prom_foreign_post_com->currentText()=="manager"&&ui->mod_prom_e_mail->text().isEmpty())
    {

        ui->mod_prom_email_l->setText("empty"+space+"field");

        ui->mod_prom_email_l->setStyleSheet("QLabel {  color : red; }");

        ui->mod_prom_email_l->show();

        res++;
    }
    else if(ui->mod_prom_foreign_post_com->currentText()=="manager"&&p.is_valid_email(ui->mod_prom_e_mail->text())==false)
    {

        ui->mod_prom_email_l->setText(msg2+space+"email");

        ui->mod_prom_email_l->setStyleSheet("QLabel {  color : blue; }");

        ui->mod_prom_email_l->show();

        res++;
    }
    if(ui->mod_prom_foreign_post_com->currentText()=="driver"&&ui->mod_prom_years_led->currentIndex()==0)
    {
        ui->mod_prom_driver_l_ex_d->setText(msg+space+"year");

        ui->mod_prom_driver_l_ex_d->setStyleSheet("QLabel {  color : red; }");

        ui->mod_prom_driver_l_ex_d->show();

        res++;
    }
    if(ui->mod_prom_foreign_post_com->currentText()=="driver"&&ui->mod_prom_months_led->currentIndex()==0)
    {
        ui->mod_prom_driver_l_ex_d->setText(msg+space+"month");

        ui->mod_prom_driver_l_ex_d->setStyleSheet("QLabel {  color : red; }");

        ui->mod_prom_driver_l_ex_d->show();

        res++;
    }
    if(ui->mod_prom_foreign_post_com->currentText()=="driver"&&ui->mod_prom_days_led->currentIndex()==0)
    {
        ui->mod_prom_driver_l_ex_d->setText(msg+space+"day");

        ui->mod_prom_driver_l_ex_d->setStyleSheet("QLabel {  color : red; }");

        ui->mod_prom_driver_l_ex_d->show();

        res++;
    }

    if(ui->mod_prom_foreign_post_com->currentText()=="driver"&&ui->mod_prom_years_led->currentIndex()==0&&ui->mod_prom_days_led->currentIndex()==0&&ui->mod_prom_months_led->currentIndex()==0)
    {
        ui->mod_prom_driver_l_ex_d->setText(msg+space+"date");

        ui->mod_prom_driver_l_ex_d->setStyleSheet("QLabel {  color : red; }");

        ui->mod_prom_driver_l_ex_d->show();

        res++;
    }
    if(res>0)
    {
        return false ;
    }
    else
    {
        return true ;
    }
}
void  gestionrh::on_create_employee_clicked()
{
    this->name=ui->name->text();
    this->family_name=ui->family_name->text();
    this->social_sn=ui->ssn->text().toInt();
    this->social_state=ui->social_state->currentText();
    int d=ui->days_b->currentText().toInt();
    int m=ui->months_b->currentText().toInt();
    int y=ui->years_b->currentText().toInt();
    QDate b_date(y,m,d);
    this->birthdate=b_date;
    this->phone_number=ui->phone_n->text().toInt();
    this->Cin=ui->cin->text().toInt();
    this->gender=ui->gender->currentText();
    this->post=ui->post->currentText();
    this->salary=ui->salary->text().toDouble();
    this->contract_type=ui->contract->currentText();
    this->paiment_type=ui->paiment->currentText();
    this->interveiwer=ui->interveiwer->currentText().toInt();
    this->c_v=ui->cv->text();
    this->m_l=ui->motivation_letter->text();
    this->city=ui->city->text();
    this->area=ui->area->text();
    this->zip_code=ui->zip_code->text();
    this->street=ui->street->text();
    this->activity=true;
    this->c_v=ui->cv->text();
    this->m_l=ui->motivation_letter->text();
    this->workspace=ui->building->currentText().toInt();

    /*----------driver-----------------*/
    this->big_trucks=ui->yes_1->checkState();
    this->small_trucks=ui->yes_2->checkState();
    this->lisence=ui->driver_lisence->text().toInt();
    d=ui->days_led->currentText().toInt();
    m=ui->months_led->currentText().toInt();
    y=ui->years_led->currentText().toInt();
    QDate d_date(y,m,d);
    this->expiration_date=d_date;

    /*-------manager----------*/
    email=ui->e_mail->text();
    type=ui->type->currentText();
    pawd=name+Cin;
    /*--------inputcontrol------------*/


    if(is_add_data_existant_and_valid()==false)
    {
        QMessageBox::critical(this,"Hamadi ERP","the data you entred seems unvalid \n recheck please",QMessageBox::Ok);
    }
    else
    {
        if(post=="manager")
        {
            manager man(pawd,type,email,name,family_name,birthdate,social_state,social_sn,zip_code,street,area,city, phone_number,Cin,salary,post ,gender ,activity ,contract_type ,paiment_type ,interveiwer,c_v,m_l, photo,workspace);
            if(man.add_manager()==false)
            {
                QMessageBox::critical(this,"Hamadi ERP","something went wrong with data base",QMessageBox::Ok);
            }
            else
            {
                QMessageBox::information(this,"Hamadi ERP","added with success",QMessageBox::Ok);
            }
        }
        else if(post=="driver")
        {
            driver dri(lisence,big_trucks,small_trucks,expiration_date,name,family_name,birthdate,social_state,social_sn,zip_code,street,area,city, phone_number,Cin,salary,post ,gender ,activity ,contract_type ,paiment_type ,interveiwer,c_v,m_l, photo,workspace);
            if(dri.add_driver()==false)
            {
                QMessageBox::critical(this,"Hamadi ERP","something went wrong with data base",QMessageBox::Ok);
            }
            else
            {
                QMessageBox::information(this,"Hamadi ERP","added with success",QMessageBox::Ok);
            }

        }
        else
        {
            e =new employee(name,family_name,birthdate,social_state,social_sn,zip_code,street,area,city, phone_number,Cin,salary,post ,gender ,activity ,contract_type ,paiment_type ,interveiwer,c_v,m_l, photo,workspace);
            if( e->add_employee()==false)
            {
                QMessageBox::critical(this,"Hamadi ERP","something went wrong with data base",QMessageBox::Ok);
            }
            else
            {
                QMessageBox::information(this,"Hamadi ERP","added with success",QMessageBox::Ok);
            }
        }
    }
    insert_employee_combobox_data();
}
void  gestionrh::on_interveiwer_search_textEdited()
{
    e=new(employee);

    QString text=ui->interveiwer_search->text();
    ui->interveiwer->clear();
    ui->interveiwer->setModel( e->employee_id_list_dynamic(text));
}
void  gestionrh::on_interveiwer_search_returnPressed()
{
    e=new(employee);
    e->select_employee(ui->interveiwer->currentText().toInt());
    ui->interveiwer_search->clear();
    ui->interveiwer_search->setText( e->Get_name()+" "+ e->Get_lastname());
    ui->inter_phone_number->setText(QString::number( e->Get_phone_number()));
}
void  gestionrh::on_add_cv_clicked()
{

    QString  fileName = QFileDialog::getOpenFileName(this,
                                                     tr("add curriculum vitae"), "", tr("Tout les Documents Word (*.docx,*.pdf,*.docm"));
    ui->cv->setText(fileName);
}
void  gestionrh::on_add_motivationletter_clicked()
{
    QString  fileName = QFileDialog::getOpenFileName(this,
                                                     tr("add motivation letter"), "", tr("Tout les Documents Word (*.docx,*.pdf,*.docm"));
    ui->motivation_letter->setText(fileName);
}
void  gestionrh::on_add_photo_clicked()
{
    photo = QFileDialog::getOpenFileName(this,
                                         tr("add employee photo"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    QPixmap mapp(photo);
    QSize Qlabel_size=ui->pix_map_photo->size();
    QPixmap scaled_map=mapp.scaled(Qlabel_size);
    ui->pix_map_photo->setPixmap(scaled_map);
}
void  gestionrh::on_search_employee_textEdited()
{
    e=new(employee);
    QString aux=ui->search_employee->text();
    QString choice=ui->Employe_groupe->currentText();
    ui->employee_list->setModel( e->employee_list(aux,choice));
    delete e;
}
void  gestionrh::on_search_employee_returnPressed()
{
    e=new(employee);

    ui->employee_list->setModel( e->employee_list());
    delete e;

}
void  gestionrh::on_search_employee_textChanged()
{
    e=new(employee);
    /* QString aux=ui->search_employee->text();

       QString choice=ui->Employe_groupe->currentText();
       if(ui->order_by_post->checkState())
       {ui->employee_list->setModel( e->employee_list(aux));}
       else

      { ui->employee_list->setModel( e->employee_list(aux,choice));}*/
    delete e;

}
void  gestionrh::on_export_employee_list_clicked()//blob
{

    QSqlQueryModel  *model = new QSqlQueryModel() ;
    QString linki = QFileDialog::getSaveFileName(this, tr("Export CSV"),"/liste_employees.csv", tr("Comma Separated Values (*.csv)"));


    e=new (employee);

    int x = 0;
    QString exportdata;
    model=e->employee_list();
    int counthidden = 0, jint = 0;

    while (jint < model->columnCount())
    {

        counthidden+=ui->employee_list->isColumnHidden(jint);
        jint++;
    }


    while (x < model->columnCount())
    {

        if (!ui->employee_list->isColumnHidden(x))
        {

            exportdata.append(model->headerData(x,Qt::Horizontal,Qt::DisplayRole).toString());
            //msgbox(exportdata);
            if (model->columnCount() - x != counthidden)
                exportdata.append(";");
            else
                exportdata.append("\n");

        }
        x++;

    }

    int z = 0;

    exportdata.append("\n");
    while (z < model->rowCount())
    {

        x = 0;
        while (x < model->columnCount())
        {
            if (!ui->employee_list->isColumnHidden(x))
            {

                exportdata.append(model->data(model->index(z,x),Qt::DisplayRole).toString());


                if (model->columnCount() - x != counthidden)
                {
                    exportdata.append(";");

                }
                else
                {
                    exportdata.append("\n");

                }
            }

            x++;

        }
        exportdata.append("\n");
        z++;
    }



    QFile file;
    if (!linki.isEmpty())
    {
        file.setFileName(linki);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
    }
    QByteArray ttext;
    ttext.append(exportdata);
    file.write(ttext);
    /* closing the file */

}
void  gestionrh::on_mod_id_employee_currentIndexChanged()
{

    insert_employee_data();
}
void  gestionrh::insert_employee_data()
{
    e=new employee();
    e->select_employee(ui->mod_id_employee->currentText().toInt());
    ui->mod_name->setText(e->Get_name());
    ui->mod_family_name->setText(e->Get_lastname());
    QString y=QString::number(e->Get_phone_number());
    ui->mod_phone_n->setText(y);
    QPixmap mapp(photo=e->Get_photo());
    QSize Qlabel_size=ui->mod_pix_map_photo->size();
    QPixmap scaled_map=mapp.scaled(Qlabel_size);
    ui->mod_pix_map_photo->setPixmap(scaled_map);
    ui->mod_motivation_letter->setText( e->Get_m_l());
    ui->mod_cv->setText( e->Get_c_v());
    ui->mod_paiment->setCurrentText(e->Get_paiment_type());
    ui->mod_contract->setCurrentText( e->Get_contract_type());
    QString x=QString::number( e->Get_social_sn());
    ui->mod_ssn->setText(x);
    x=QString::number( e->Get_salary());
    ui->mod_salary->setText(x);
    ui->mod_street->setText( e->Get_street());
    ui->mod_zip_code->setText( e->Get_zip_code());
    ui->mod_area->setText(e->Get_area());
    ui->mod_city->setText(e->Get_city());
    x=QString::number(e->Get_Cin());
    ui->mod_cin->setText(x);
    x=QString::number(e->Get_interveiwer());
    ui->mod_id_interveiwer->setText(x);
    x=QString::number(e->Get_building());
    ui->mod_id_building->setText(x);
    x=e->Get_post();
    ui->mod_gender->setCurrentText(e->Get_gender());
    ui->mod_social_state->setCurrentText(e->Get_social_state());
    ui->mod_post->setCurrentText(x);
    QDate date_b=e->Get_birthdate();
    int year;
    int month;
    int day;
    day=date_b.day();
    month=date_b.month();
    year=date_b.year();
    ui->mod_days_b->setCurrentIndex(day);
    ui->mod_months_b->setCurrentIndex(month);
    ui->mod_years_b->setCurrentIndex(year-1919);
    QString choice=x;

    if(choice=="manager")
    {
        m=new (manager) ;
        m->select_manager(ui->mod_id_employee->currentText().toInt());
        ui->mod_e_mail->setText(m->get_email());
        ui->mod_type->setCurrentText(m->gettype());

    }
    if(choice=="driver")
    {
        d=new(driver);
        d->select_driver( e->Get_id_employee());
        QString x ;
        x=QString::number(d->Get_lisence());

        ui->mod_driver_lisence->setText(x);
        ui->mod_yes_1->setChecked(d->Get_big_trucks());
        ui->mod_yes_2->setChecked(d->Get_small_trucks());
        QDate date;
        date=d->Get_expiration_date();
        int days;
        int monthes;
        int years;
        days=date.day();
        monthes=date.month();
        years=date.year();
        ui->mod_years_led->setCurrentIndex(years-1969);
        ui->mod_months_led->setCurrentIndex(monthes);
        ui->mod_days_led->setCurrentIndex(days);


    }
    else
    {
        /* do nothing */
    }




}
void  gestionrh::on_search_building_textChanged()
{
    QString var=ui->search_building->text();
    building b ;
    ui->building->setModel(b.building_id_list(var));
}
void  gestionrh::hide_graph_titels()
{
    ui->red_graph->hide();
    ui->blue_graph->hide();
    ui->green_graph->hide();
    ui->yellow_graph->hide();
    ui->black_graph->hide();
}
void  gestionrh::hide_graph_side_bar()
{
    ui->zero_graph->hide();
    ui->one_graph->hide();
    ui->two_graph->hide();
    ui->three_graph->hide();
    ui->four_graph->hide();
    ui->five_graph->hide();
    ui->six_graph->hide();
    ui->seven_graph->hide();
    ui->eight_graph->hide();
    ui->nine_graph->hide();
    ui->ten_graph->hide();

}
void  gestionrh::on_employee_list_doubleClicked(const QModelIndex &index)
{
    int pos = index.row();//reading the position from the index presented as parameter from the function
    int res= QMessageBox::warning(0,"Hamadi ERP","you have preformeed a double click\n on an employee\n what do you want to do  ","modify","promote","move");
    if(res==0)
    {
        if(ui->employee_list->model()->data(ui->employee_list->model()->index(pos,13)).toString()=="manager")
        {
            QMessageBox::critical(0,"Hamadi ERP","this procedure cannot be sustained \n managers promotions are not supported",QMessageBox::Ok);
        }
        else if(ui->employee_list->model()->data(ui->employee_list->model()->index(pos,13)).toString()=="driver")
        {
            QMessageBox::critical(0,"Hamadi ERP","this procedure cannot be sustained \n drivers promotions are not supported",QMessageBox::Ok);
        }
        else
        {
            int id_employee=ui->employee_list->model()->data(ui->employee_list->model()->index(pos,0)).toInt();//reading id from first column at x row
            ui->employee->setCurrentIndex(1);//setting tabwidget to the update layout (index =1 )
            ui->Update->setCurrentIndex(res);//setting the tabwidget to the modify layout (index=0 )
            ui->mod_id_employee->setCurrentText(QString::number(id_employee));// setting combobox on the id read from the click space

        }
    }
    else if(res==1)
    {
        int id_employee=ui->employee_list->model()->data(ui->employee_list->model()->index(pos,0)).toInt();//reading id from first column at x row
        ui->employee->setCurrentIndex(1);//setting tabwidget to the update layout (index =1 )
        ui->Update->setCurrentIndex(res);//setting the tabwidget to the modify layout (index=0 )
        ui->mod_prom_id_employee->setCurrentText(QString::number(id_employee));// setting combobox on the id read from the click space
    }
    else if(res==2)
    {
        int id_employee=ui->employee_list->model()->data(ui->employee_list->model()->index(pos,0)).toInt();//reading id from first column at x row
        ui->employee->setCurrentIndex(1);//setting tabwidget to the update layout (index =1 )
        ui->Update->setCurrentIndex(res);//setting the tabwidget to the modify layout (index=0 )
        ui->mod_move_id_employee->setCurrentText(QString::number(id_employee));// setting combobox on the id read from the click space
        ui->take_me_back_to_search->show();
    }
}
void  gestionrh::on_mod_update_employee_clicked()
{
    this->name=ui->mod_name->text();
    this->family_name=ui->mod_family_name->text();
    this->social_sn=ui->mod_ssn->text().toInt();
    this->social_state=ui->mod_social_state->currentText();
    int d=ui->mod_days_b->currentText().toInt();
    int m=ui->mod_months_b->currentText().toInt();
    int y=ui->mod_years_b->currentText().toInt();
    QDate b_date(y,m,d);
    this->birthdate=b_date;
    this->phone_number=ui->mod_phone_n->text().toInt();
    this->Cin=ui->mod_cin->text().toInt();
    this->gender=ui->mod_gender->currentText();
    this->post=ui->mod_post->currentText();
    this->salary=ui->mod_salary->text().toDouble();
    this->contract_type=ui->mod_contract->currentText();
    this->paiment_type=ui->mod_paiment->currentText();
    this->interveiwer=ui->mod_interveiwer->currentText().toInt();
    this->m_l=ui->mod_motivation_letter->text();
    this->city=ui->mod_city->text();
    this->area=ui->mod_area->text();
    this->zip_code=ui->mod_zip_code->text();
    this->street=ui->mod_street->text();
    this->activity=true;
    this->c_v=ui->mod_cv->text();
    this->m_l=ui->mod_motivation_letter->text();
    this->workspace=ui->mod_building->currentText().toInt();

    /*----------driver-----------------*/
    this->big_trucks=ui->mod_yes_1->checkState();
    this->small_trucks=ui->mod_yes_2->checkState();
    this->lisence=ui->mod_driver_lisence->text().toInt();
    d=ui->days_led->currentText().toInt();
    m=ui->mod_months_led->currentText().toInt();
    y=ui->years_led->currentText().toInt();
    QDate d_date(y,m,d);
    this->expiration_date=d_date;

    /*-------manager----------*/
    email=ui->mod_e_mail->text();
    type=ui->mod_type->currentText();
    pawd=name+Cin;
    /*--------inputcontrol------------*/


    if(is_mod_data_existant_and_valid()==false)
    {
        QMessageBox::critical(this,"Hamadi ERP","the data you entred seems unvalid \n recheck please",QMessageBox::Ok);
    }
    else
    {
        if(post=="manager")
        {
            this->m=new manager(type,email,name,family_name,birthdate,social_state,social_sn,zip_code,street,area,city, phone_number,Cin,salary,post ,gender ,activity ,contract_type ,paiment_type ,interveiwer,c_v,m_l, photo,workspace);
            if(this->m->modify_manager(ui->mod_id_employee->currentText().toInt())==false)
            {
                QMessageBox::critical(this,"Hamadi ERP","something went wrong with data base",QMessageBox::Ok);
            }
            else
            {
                QMessageBox::information(this,"Hamadi ERP","added with success",QMessageBox::Ok);
            }
        }
        else if(post=="driver")
        {
            this->d=new driver (lisence,big_trucks,small_trucks,expiration_date,name,family_name,birthdate,social_state,social_sn,zip_code,street,area,city, phone_number,Cin,salary,post ,gender ,activity ,contract_type ,paiment_type ,interveiwer,c_v,m_l, photo,workspace);
            if(this->d->modify_driver(ui->mod_id_employee->currentText().toInt()==false))
            {
                QMessageBox::critical(this,"Hamadi ERP","something went wrong with data base",QMessageBox::Ok);
            }
            else
            {
                QMessageBox::information(this,"Hamadi ERP","added with success",QMessageBox::Ok);
            }
        }
        else
        {
            e =new employee(name,family_name,birthdate,social_state,social_sn,zip_code,street,area,city, phone_number,Cin,salary,post ,gender ,activity ,contract_type ,paiment_type ,interveiwer,c_v,m_l, photo,workspace);
            if( e->modify_employee(ui->mod_id_employee->currentText().toInt())==false)
            {
                QMessageBox::critical(this,"Hamadi ERP","something went wrong with data base",QMessageBox::Ok);
            }
            else
            {
                QMessageBox::information(this,"Hamadi ERP","added with success",QMessageBox::Ok);
            }
        }



    }
}
void  gestionrh::on_mod_clear_clicked()
{
    insert_employee_data();
}
void  gestionrh::hide_mod_alert_labels()
{
    ui->mod_big_trucks_l->hide();
    ui->mod_birthdate_l->hide();
    ui->mod_building_l->hide();
    ui->mod_cvital_l->hide();
    ui->mod_b_salary_l->hide();
    ui->mod_email_l->hide();
    ui->mod_citizenin_l->hide();
    ui->mod_family_name_l->hide();
    ui->mod_name_l->hide();
    ui->mod_type_l->hide();
    ui->mod_type_p_l->hide();
    ui->mod_gender_l->hide();
    ui->mod_driver_serial->hide();
    ui->mod_driver_l_ex_d->hide();
    ui->mod_big_trucks_l->hide();
    ui->mod_small_trucks_l->hide();
    ui->mod_street_l->hide();
    ui->mod_area_l->hide();
    ui->mod_city_l->hide();
    ui->mod_zip_code_l->hide();
    ui->mod_type_c_l->hide();
    ui->mod_type_p_l->hide();
    ui->mod_social_s_l->hide();
    ui->mod_phone_number_l->hide();
    ui->mod_post_l->hide();
    ui->mod_ssnumber_l->hide();
    ui->mod_interveiwer_l->hide();
    ui->mod_letter_l->hide();
}
bool  gestionrh::is_mod_data_existant_and_valid()
{
    hide_mod_alert_labels();
    int res=0 ;
    QString msg2="unvalid";
    QString space=" ";
    inputcontrol p;
    QString msg="empty field";
    if(ui->mod_name->text().isEmpty())
    {
        ui->mod_name_l->setText(msg);
        ui->mod_name_l->setStyleSheet("QLabel {  color : red; }");
        ui->mod_name_l->show();
        res++;
    }
    else if(p.is_valid_name(ui->mod_name->text())==false)
    {
        ui->mod_name_l->setText(msg2+space+"name");
        ui->mod_name_l->setStyleSheet("QLabel {  color : blue; }");
        ui->mod_name_l->show();
        res++;
    }
    if(ui->mod_family_name->text().isEmpty())
    {
        ui->mod_family_name_l->setText(msg);
        ui->mod_family_name_l->setStyleSheet("QLabel {color : red; }");
        ui->mod_family_name_l->show();
        res++;
    }
    else if(p.is_valid_name(ui->mod_family_name->text())==false)
    {
        ui->mod_family_name_l->setText(msg2+space+"last name");
        ui->mod_family_name_l->setStyleSheet("QLabel {color : blue; }");
        ui->mod_family_name_l->show();
        res++;
    }
    if(ui->mod_ssn->text().isEmpty())
    {
        ui->mod_ssnumber_l->setText(msg);
        ui->mod_ssnumber_l->setStyleSheet("QLabel {color : red; }");
        ui->mod_ssnumber_l->show();
        res++;
    }
    else if(p.is_number(ui->mod_ssn->text())==false)
    {
        ui->mod_ssnumber_l->setText(msg2+space+"s.s number");
        ui->mod_ssnumber_l->setStyleSheet("QLabel {color : blue; }");
        ui->mod_ssnumber_l->show();
        res++;
    }
    if(ui->mod_social_state->currentIndex()==0)
    {
        ui->mod_social_s_l->setText("unspecified social state");
        ui->mod_social_s_l->setStyleSheet("QLabel {color : red; }");
        ui->mod_social_s_l->show();
        res++;
    }
    if(ui->mod_phone_n->text().isEmpty())
    {
        ui->mod_phone_number_l->setText(msg);
        ui->mod_phone_number_l->setStyleSheet("QLabel {color : red; }");
        ui->mod_phone_number_l->show();
        res++;
    }
    else if(p.is_valid_cin_or_phone(ui->mod_phone_n->text())==false)
    {
        ui->mod_phone_number_l->setText(msg2+space+"phone number");
        ui->mod_phone_number_l->setStyleSheet("QLabel {color : blue; }");
        ui->mod_phone_number_l->show();
        res++;
    }
    if(ui->mod_cin->text().isEmpty())
    {
        ui->mod_citizenin_l->setText(msg);
        ui->mod_citizenin_l->setStyleSheet("QLabel {color : red; }");
        ui->mod_citizenin_l->show();
        res++;
    }
    else if(p.is_valid_cin_or_phone(ui->mod_cin->text())==false)
    {
        ui->mod_citizenin_l->setText(msg2+space+"cin");
        ui->mod_citizenin_l->setStyleSheet("QLabel {color : blue; }");
        ui->mod_citizenin_l->show();
        res++;
    }
    if(ui->mod_gender->currentIndex()==0)
    {
        ui->mod_gender_l->setText("unspecified gender");
        ui->mod_gender_l->setStyleSheet("QLabel {color : red; }");
        ui->mod_gender_l->show();
        res++;
    }
    if(ui->mod_post->currentIndex()==0)
    {
        ui->mod_post_l->setText("unspecified post");
        ui->mod_post_l->setStyleSheet("QLabel {color : red; }");
        ui->mod_post_l->show();
        res++;
    }
    if(ui->mod_salary->text().isEmpty())
    {
        ui->mod_b_salary_l->setText(msg);
        ui->mod_b_salary_l->setStyleSheet("QLabel {color : red; }");
        ui->mod_b_salary_l->show();
        res++;
    }
    else if(p.is_valid_float(ui->mod_salary->text())==false)
    {
        ui->mod_b_salary_l->setText(msg2+space+"salary");
        ui->mod_b_salary_l->setStyleSheet("QLabel {color : blue; }");
        ui->mod_b_salary_l->show();
        res++;
    }
    if(ui->mod_contract->currentIndex()==0)
    {
        ui->mod_type_c_l->setText("unspecified contract type");
        ui->mod_type_c_l->setStyleSheet("QLabel {color : red; }");
        ui->mod_type_c_l->show();
        res++;
    }
    if(ui->mod_paiment->currentIndex()==0)
    {
        ui->mod_type_p_l->setText("unspecified paiment type");
        ui->mod_type_p_l->setStyleSheet("QLabel {color : red; }");
        ui->mod_type_p_l->show();
        res++;
    }
    if(ui->mod_cv->text().isEmpty())
    {
        ui->mod_cvital_l->setText(msg);
        ui->mod_cvital_l->setStyleSheet("QLabel {color : red; }");
        ui->mod_cvital_l->show();
        res++;
    }
    if(ui->mod_motivation_letter->text().isEmpty())
    {
        ui->mod_letter_l->setText(msg);
        ui->mod_letter_l->setStyleSheet("QLabel {color : red; }");
        ui->mod_letter_l->show();
        res++;
    }
    if(ui->mod_street->text().isEmpty())
    {
        ui->mod_street_l->setText(msg);
        ui->mod_street_l->setStyleSheet("QLabel {color : red; }");
        ui->mod_street_l->show();
        res++;
    }
    if(ui->mod_city->text().isEmpty())
    {
        ui->mod_city_l->setText(msg);
        ui->mod_city_l->setStyleSheet("QLabel {color : red; }");
        ui->mod_city_l->show();
        res++;
    }
    if(ui->mod_area->text().isEmpty())
    {
        ui->mod_area_l->setText(msg);
        ui->mod_area_l->setStyleSheet("QLabel {color : red; }");
        ui->mod_area_l->show();
        res++;
    }
    if(ui->mod_zip_code->text().isEmpty())
    {
        ui->mod_zip_code_l->setText(msg);
        ui->mod_zip_code_l->setStyleSheet("QLabel {color : red; }");
        ui->mod_zip_code_l->show();
        res++;
    }
    if(ui->mod_days_b->currentIndex()==0)
    {
        ui->mod_birthdate_l->setText("unspecified day");
        ui->mod_birthdate_l->setStyleSheet("QLabel {color : red; }");
        ui->mod_birthdate_l->show();
        res++;
    }
    if(ui->mod_years_b->currentIndex()==0)
    {
        ui->mod_birthdate_l->setText("unspecified year");
        ui->mod_birthdate_l->setStyleSheet("QLabel {color : red; }");
        ui->mod_birthdate_l->show();
        res++;
    }
    if(ui->mod_months_b->currentIndex()==0)
    {
        ui->mod_birthdate_l->setText("unspecified month");
        ui->mod_birthdate_l->setStyleSheet("QLabel {color : red; }");
        ui->mod_birthdate_l->show();
        res++;
    }
    if(ui->mod_months_b->currentIndex()==0&&ui->mod_years_b->currentIndex()==0&&ui->mod_days_b->currentIndex()==0)
    {
        ui->birthdate_l->setText("unspecified birthdate");
        ui->mod_birthdate_l->setStyleSheet("QLabel {color : red; }");
        ui->mod_birthdate_l->show();
        res++;
    }
    if(ui->mod_days_led->currentIndex()==0&&ui->mod_post->currentIndex()==3)
    {
        ui->mod_driver_l_ex_d->setText("unspecified day");
        ui->mod_driver_l_ex_d->setStyleSheet("QLabel {color : red; }");
        ui->mod_driver_l_ex_d->show();
        res++;
    }
    if(ui->mod_years_led->currentIndex()==0&&ui->mod_post->currentIndex()==3)
    {
        ui->mod_driver_l_ex_d->setText("unspecified year");
        ui->mod_driver_l_ex_d->setStyleSheet("QLabel {color : red; }");
        ui->mod_driver_l_ex_d->show();
        res++;
    }
    if(ui->mod_months_led->currentIndex()==0&&ui->mod_post->currentIndex()==3)
    {
        ui->mod_driver_l_ex_d->setText("unspecified month");
        ui->mod_driver_l_ex_d->setStyleSheet("QLabel {color : red; }");
        ui->mod_driver_l_ex_d->show();
        res++;
    }
    if(ui->mod_months_led->currentIndex()==0&&ui->mod_years_led->currentIndex()==0&&ui->mod_days_led->currentIndex()==0&&ui->mod_post->currentIndex()==3)
    {
        ui->mod_driver_l_ex_d->setText("unspecified expiration date");
        ui->mod_driver_l_ex_d->setStyleSheet("QLabel {color : red; }");
        ui->mod_driver_l_ex_d->show();
        res++;
    }
    if(ui->mod_driver_lisence->text().isEmpty()&&ui->mod_post->currentIndex()==3)
    {
        ui->mod_driver_serial->setText(msg);
        ui->mod_driver_serial->setStyleSheet("QLabel {color : red; }");
        ui->mod_driver_serial->show();
        res++;
    }
    if(ui->mod_e_mail->text().isEmpty()&&ui->mod_post->currentIndex()==4)
    {
        ui->mod_email_l->setText(msg);
        ui->mod_email_l->setStyleSheet("QLabel {color : red; }");
        ui->mod_email_l->show();
        res++;
    }
    else if(p.is_valid_email(ui->mod_e_mail->text())==false&&ui->mod_post->currentIndex()==4)
    {
        ui->mod_email_l->setText(msg2+space+"email");
        ui->mod_email_l->setStyleSheet("QLabel {color : blue; }");
        ui->mod_email_l->show();
        res++;
    }
    if(ui->mod_type->currentIndex()==0&&ui->mod_post->currentIndex()==4)
    {
        ui->mod_type_l->setText("unspecified type");
        ui->mod_type_l->setStyleSheet("QLabel {color : red; }");
        ui->mod_type_l->show();
        res++;
    }
    if(res>0)
    {
        return false;
    }
    else
    {
        return true;
    }


}
void  gestionrh::on_delete_employee_clicked()
{
    e=new employee ();
    if(ui->mod_id_employee->currentText().isEmpty())
    {
        QMessageBox::critical(0,"Hamadi ERP","no employees specified to delete",QMessageBox::Ok);
    }
    else
    {
        if(QMessageBox::warning(0,"Hamadi ERP","you are about to archive this employee \n in the data base \n are you sure ?","yes","no")==0)
        {
            if(e->delete_employee( ui->mod_id_employee->currentText().toInt(), "archive"))
            {
                QMessageBox::information(0,"Hamadi ERP","employee deleted with success",QMessageBox::Ok);
            }
            else
            {
                QMessageBox::critical(0,"Hamadi ERP","data base runtime error",QMessageBox::Ok);
            }
            insert_employee_combobox_data();
        }
        else {
            QMessageBox::information(0,"Hamadi ERP","archive request aborted",QMessageBox::Ok);
        }
    }

}
void  gestionrh::insert_employee_combobox_data()
{
    e=new employee();
    b=new building();
    r=new raises();
    ui->id_raise_update->setModel(r->select_all_raises_ids());
    ui->move_building_id_com->setModel(b->building_id_list());
    ui->id_raise_delete->setModel(r->select_all_raises_ids());
    ui->mod_id_employee->setModel( e->employee_id_list());
    ui->interveiwer->setModel( e->employee_list_by_post("interveiwer"));
    ui->mod_prom_id_employee->setModel(e->employee_id_list_with_exception("manager","driver"));
    ui->mod_move_id_employee->setModel(e->employee_id_list());
    ui->raise_id_employee->setModel(e->employee_id_list());
    ui->move_shift_building_id_com->setModel(b->building_id_list());
    ui->raise_id_employee_reassigne->setModel(e->employee_id_list());
    ui->shift_creating_id_employee->setModel(e->employee_list_shift(ui->move_shift_building_id_com->currentText(),"manager"));



}
void gestionrh::on_vac_id_employee_currentIndexChanged()
{
    e=new employee();
    v=new vacation();
    ui->vacations_list->setModel(v->vacation_list_by_employee(ui->vac_id_employee->currentText()));
    ui->vacations_list->resizeColumnsToContents();
    ui->vacations_list->resizeRowsToContents();
    e->select_employee(ui->vac_id_employee->currentText().toInt());
    ui->vac_emp_family_name_le->setText(e->Get_lastname());
    ui->vac_emp_name_le->setText(e->Get_name());
    QPixmap mypixmap(e->Get_photo());
    QPixmap scaledpixmap=mypixmap.scaled(ui->vac_emp_photo_pix_map->width(),ui->vac_emp_photo_pix_map->height());
    ui->vac_emp_photo_pix_map->setPixmap(scaledpixmap);
    delete e;
    delete v;
}
void gestionrh::hide_vacation_alert_labels()
{
    ui->type_of_vacation_error_lab->hide();
    ui->start_date_vacation_error_lab->hide();
    ui->end_date_vacation_error_lab->hide();
    ui->days_vacation_error_lab->hide();
}
void gestionrh::on_create_vacation_clicked()
{

    hide_vacation_alert_labels();

    int res=0;

    {
        /*----------------- input control ----------*/
        if(ui->vac_type->currentIndex()==0)
        {
            ui->type_of_vacation_error_lab->setText("specify a vacation type please ");
            ui->type_of_vacation_error_lab->setStyleSheet("QLabel {  color : red; }");
            ui->type_of_vacation_error_lab->show();
            res++;
        }
        if(ui->vac_start_days->currentIndex()==0)
        {
            ui->start_date_vacation_error_lab->setText("specify a day  for the starting date please ");
            ui->start_date_vacation_error_lab->setStyleSheet("QLabel {  color : red; }");
            ui->start_date_vacation_error_lab->show();
            res++;
        }
        else if(ui->vac_start_months->currentIndex()==0)
        {
            ui->start_date_vacation_error_lab->setText("specify a month  for the starting date please ");
            ui->start_date_vacation_error_lab->setStyleSheet("QLabel {  color : red; }");
            ui->start_date_vacation_error_lab->show();
            res++;
        }
        else if(ui->vac_start_years->currentIndex()==0)
        {
            ui->start_date_vacation_error_lab->setText("specify a year  for the starting date please ");
            ui->start_date_vacation_error_lab->setStyleSheet("QLabel {  color : red; }");
            ui->start_date_vacation_error_lab->show();
            res++;
        }
        else if(ui->vac_start_days->currentIndex()==0&&ui->vac_start_months->currentIndex()==0&&ui->vac_start_years->currentIndex()==0)
        {
            ui->start_date_vacation_error_lab->setText("unspecified starting date  ");
            ui->start_date_vacation_error_lab->setStyleSheet("QLabel {  color : red; }");
            ui->start_date_vacation_error_lab->show();
            res++;
        }
        if(ui->vac_end_days->currentIndex()==0)
        {
            ui->end_date_vacation_error_lab->setText("specify a day  for the starting date please ");
            ui->end_date_vacation_error_lab->setStyleSheet("QLabel {  color : red; }");
            ui->end_date_vacation_error_lab->show();
            res++;
        }
        else if(ui->vac_end_months->currentIndex()==0)
        {
            ui->end_date_vacation_error_lab->setText("specify a month  for the starting date please ");
            ui->end_date_vacation_error_lab->setStyleSheet("QLabel {  color : red; }");
            ui->end_date_vacation_error_lab->show();
            res++;
        }
        else if(ui->vac_end_years->currentIndex()==0)
        {
            ui->end_date_vacation_error_lab->setText("specify a year  for the starting date please ");
            ui->end_date_vacation_error_lab->setStyleSheet("QLabel {  color : red; }");
            ui->end_date_vacation_error_lab->show();
            res++;
        }
        else if(ui->vac_end_days->currentIndex()==0&&ui->vac_end_months->currentIndex()==0&&ui->vac_end_years->currentIndex()==0)
        {
            ui->end_date_vacation_error_lab->setText("unspecified starting date  ");
            ui->end_date_vacation_error_lab->setStyleSheet("QLabel {  color : red; }");
            ui->end_date_vacation_error_lab->show();
            res++;
        }
        if(ui->number_of_vacation_days->value()==0)
        {
            ui->days_vacation_error_lab->setText("unspecified vacation length");
            ui->end_date_vacation_error_lab->setStyleSheet("QLabel {  color : red; }");
            ui->days_vacation_error_lab->show();
            res++;
        }
        /*----------- data gathering----------------*/
        int d,m,y;
        vac_holder=ui->vac_id_employee->currentText().toInt();
        vac_type=ui->vac_type->currentText();
        d=ui->vac_end_days->currentText().toInt();
        m=ui->vac_end_months->currentText().toInt();
        y=ui->vac_end_years->currentText().toInt();
        QDate end_date(y,m,d);
        d=ui->vac_start_days->currentText().toInt();
        m=ui->vac_start_months->currentText().toInt();
        y=ui->vac_start_years->currentText().toInt();
        QDate start_date(y,m,d);
        /*---------- checking result ----------*/
        if(res>0)
        {
            QMessageBox::critical(0,"Hamadi ERP","the data you entred seems invalid",QMessageBox::Ok);
        }

        else  if(ui->late_declared_vacation->text()=="enable late vacation mode"&&start_date<QDate::currentDate())
        {
            QMessageBox::critical(0,"Hamadi ERP","to add a late vacation \n you must enable late vaction mode first ",QMessageBox::Ok);
        }
        //         if all is good and everything is respected in the fields
        //         we check for information  duplication in data base
        else if (res==0)
        {

            /*checking for duplications */
            v=new vacation(start_date,end_date,vac_type,vac_holder);
            if(v->does_this_vacation_already_exist())
            {
                QMessageBox::critical(0,"Hamadi ERP","you have already regitred \n this vacation ");
            }
            else if(v->does_this_vacation_has_a_shorter_or_longer_version())
            {
                if(v->Get_shorter_or_longer()=="longer")
                {
                    if (QMessageBox::warning(0,"Hamadi ERP","the vacation you specified has alrey another copy \n  of it, only end earlier. do you want \n to crop the existing one ?  ","crop","get me out of here ")==0)
                    {
                        /*call crop function */
                    }
                    else
                    {
                        /* do nothing */
                    }
                }
                else if(v->Get_shorter_or_longer()=="shorter")
                {

                    if (QMessageBox::warning(0,"Hamadi ERP","the vacation you specified has already another copy \n  of it, only end Later. do you want \n to extend the existing one ?  ","extend","get me out of here ")==0)
                    {
                        /*call extend function */
                    }
                    else
                    {
                        /* do nothing */
                    }
                }
            }
            else if(v->does_this_vacation_colisions_with_an_existing_one())

            {
                if(v->Get_collision_direction()=="left")
                {
                    if( QMessageBox::warning(0,"Hamadi ERP","it seems that you have specified \n a vacancy that ends at the very time another one  starts \n do do wish to merge those two ? \n by clicking yes you merge ","yes","no")==0)
                    {
                        /* call merge function */
                    }
                    else
                    {
                        /* do nothing */
                    }
                }
                else if(v->Get_collision_direction()=="right")
                {
                    if( QMessageBox::warning(0,"Hamadi ERP","it seems that you have specified \n a vacancy that starts at the very time another one ends \n do do wish to merge those two ? \n by clicking yes you merge ","yes","no")==0)
                    {
                        /* call merge function */
                    }
                    else
                    {
                        /*do nothing */
                    }
                }

            }
            else if(v->does_this_vacation_exist_withing_an_existing_one())
            {
                QMessageBox::critical(0,"Hamadi ERP","the vacancy  you specified \n is a portion of an existing greater one ");
            }
            else if(v->does_this_vacation_have_another_vacation_living_inside_of_it())
            {
                QMessageBox::critical(0,"Hamadi ERP","the vacancy  you specified \n has an existing one within it's range ");
            }
            else if(v->does_this_vacation_have_one_of_its_limits_withing_an_existing_one())
            {
                if(v->Get_crop_or_extend()=="extend")
                    if( QMessageBox::warning(0,"Hamadi ERP","it seems that you have specified \n a vacancy that starts within an existing one \n this is not authorized... \n however you can extend it by clicking yes\n you extend the existing vacation  ","yes","no")==0)
                    {
                        /*extend */
                    }
                    else
                    {
                        /*do nothing */
                    }
                else if(v->Get_crop_or_extend()=="crop")
                {
                    if( QMessageBox::warning(0,"Hamadi ERP","it seems that you have specified \n a vacancy that ends within an existing one \n this is not authorized... \n however you can crop it by clicking yes\n you crop the existing vacation  ","yes","no")==0)
                    {
                        /*crop */
                    }
                    else
                    {
                        /*do nothing */
                    }
                }
            }

            else
            {
                /*---------------inserting into instence ------*/
                v=new vacation(start_date,end_date,vac_type,vac_holder);
                if( v->add_vacation())
                {
                    QMessageBox::information(0,"Hamadi ERP","added with success",QMessageBox::Ok);
                    delete v;
                }
                else
                {
                    QMessageBox::critical(0,"Hamadi ERP","error with data base",QMessageBox::Ok);
                }

            }

        }
    }
}
void gestionrh::on_clear_vacation_clicked()
{
    hide_vacation_alert_labels();
    ui->vac_type->setCurrentIndex(0);
    ui->vac_start_days->setCurrentIndex(0);
    ui->vac_start_months->setCurrentIndex(0);
    ui->vac_start_years->setCurrentIndex(0);
    ui->vac_end_days->setCurrentIndex(0);
    ui->vac_end_months->setCurrentIndex(0);
    ui->vac_end_years->setCurrentIndex(0);
    ui->number_of_vacation_days->setValue(0);

}
void gestionrh::show_me_the_meaning_of_being_lonely()
{
    e=new employee();
    e->select_ages();

    ui->age_pyramid->set_right_values(e->Get_male_adults_18_25(),e->Get_male_adults_25_30(),e->Get_male_adults_30_40(),e->Get_male_adults_40_50(),e->Get_male_adults_60_50());
    ui->age_pyramid->set_left_values(e->Get_female_adults_18_25(),e->Get_female_adults_25_30(),e->Get_female_adults_30_40(),e->Get_female_adults_40_50(),e->Get_female_adults_60_50());
    //ui->age_pyramid->set_right_values(2,3,4,5,6);
    //ui->age_pyramid->set_left_values(1,2,3,4,5);
    ui->age_pyramid->close();
    ui->age_pyramid->show();
    delete e;
}

void gestionrh::update_table_view()
{
    e=new employee();
    b=new building();
    r=new raises();
    ui->mod_prom_id_employee->setModel(e->employee_id_list_with_exception("manager","driver"));
    ui->mouvement_building_tb_v->setModel(b->building_list_for_mouvement_transactions(""));
    ui->vacation_employee_list_tv->setModel(e->employee_list("","All employees"));
    ui->vacation_employee_list_tv->resizeColumnsToContents();
    ui->vacation_employee_list_tv->resizeRowsToContents();
    ui->mouvement_building_tb_v->resizeColumnsToContents();
    ui->mouvement_building_tb_v->resizeRowsToContents();
    ui->raise_employee_list_tab_v->setModel(e->employee_list("","All employees"));
    ui->raise_employee_list_tab_v->resizeColumnsToContents();
    ui->raise_employee_list_tab_v->resizeRowsToContents();
    ui->raises_table_view->setModel(r->select_raises(""));
    ui->raises_table_view->resizeColumnsToContents();
    ui->raises_table_view->resizeRowsToContents();
    ui->shifts_employee_list->setModel(e->employee_list("",ui->move_shift_building_id_com->currentText(),"manager"));
    ui->shifts_employee_list->resizeColumnsToContents();
    ui->shifts_employee_list->resizeRowsToContents();
    ui->shift_building_list->setModel(b->building_list_for_mouvement_transactions(""));
    ui->shift_building_list->resizeColumnsToContents();
    ui->shift_building_list->resizeRowsToContents();
    ui->promotion_history_tab_v->setModel(e->employee_list_with_exception2("manager","driver"));
    ui->employee_list->resizeColumnsToContents();
    ui->employee_list->resizeRowsToContents();
    ui->promotion_history_tab_v->resizeColumnsToContents();
    ui->promotion_history_tab_v->resizeRowsToContents();
    ui->employee_list->setModel(e->employee_list( ui->search_employee->text(),ui->Employe_groupe->currentText()));
    ui->mouvement_history_tab_v->setModel(e->employee_list_promotion(""));
    ui->mouvement_history_tab_v->resizeColumnsToContents();
    ui->mouvement_history_tab_v->resizeRowsToContents();
    ui->raises_table_update_view->setModel(r->select_raises(""));
    ui->raises_table_update_view->resizeColumnsToContents();
    ui->raises_table_update_view->resizeRowsToContents();
    ui->raises_table_view_reassigne->setModel(e->employee_list_promotion(""));
    ui->raises_table_view_reassigne->resizeRowsToContents();
    ui->raises_table_view_reassigne->resizeColumnsToContents();
    ui->raises_table_view_delete->setModel(r->select_raises(""));
    ui->raises_table_view_delete->resizeRowsToContents();
    ui->raises_table_view_delete->resizeColumnsToContents();
    delete r;
    delete e;
}

void gestionrh::on_mod_vac_id_employee_currentIndexChanged()
{
    e=new employee();
    v=new vacation();
    ui->mod_vacations_list->setModel(v->vacation_list_by_employee(ui->mod_vac_id_employee->currentText()));
    e->select_employee(ui->mod_vac_id_employee->currentText().toInt());
    ui->mod_vac_emp_family_name_le->setText(e->Get_lastname());
    ui->mod_vac_emp_name_le->setText(e->Get_name());
    QPixmap mypixmap(e->Get_photo());
    QPixmap scaledpixmap=mypixmap.scaled(ui->mod_vac_emp_photo_pix_map->width(),ui->mod_vac_emp_photo_pix_map->height());
    ui->mod_id_vacation->setModel(v->vacation_id_list_by_employee(ui->mod_vac_id_employee->currentText()));
    ui->mod_vac_emp_photo_pix_map->setPixmap(scaledpixmap);
    delete e;
    delete v;
    bool status=false;

    ui->mod_prom_e_mail->setEnabled(status);

    ui->mod_prom_type->setEnabled(status);

    ui->mod_prom_yes->setEnabled(status);

    ui->mod_prom_yes_2->setEnabled(status);

    ui->mod_prom_driver_lisence->setEnabled(status);

    ui->mod_prom_days_led->setEnabled(status);

    ui->mod_prom_months_led->setEnabled(status);

    ui->mod_prom_years_led->setEnabled(status);
}


void gestionrh::on_statistics_tab_currentChanged()
{
    show_me_the_meaning_of_being_lonely();
}



void gestionrh::on_statistic_data_currentIndexChanged()
{

    if(ui->statistic_data->currentText()=="age")
    {
        ui->statistics_lab->clear();
        ui->statistics_lab->hide();
        e=new(employee);
        e->select_ages();
        ui->statistics->hide();
        ui->statistics->insert_values(5, e->Get_male_adults_18_25()+e->Get_female_adults_18_25(), e->Get_male_adults_25_30()+e->Get_female_adults_25_30(), e->Get_male_adults_30_40()+e->Get_female_adults_30_40(), e->Get_male_adults_40_50()+e->Get_female_adults_40_50(), e->Get_male_adults_60_50()+e->Get_female_adults_60_50());
        ui->statistics->show();
        ui->red->setText("18 to 25 ");
        ui->red->setStyleSheet("QLabel {color:red};");
        ui->red->show();
        ui->blue->setText("25 to 30");
        ui->blue->setStyleSheet("QLabel {color: blue};");
        ui->blue->show();
        ui->green->setText("30 to 40");
        ui->green->setStyleSheet("QLabel {color:green};");
        ui->green->show();
        ui->yellow->setText("40 to 50");
        ui->yellow->setStyleSheet("QLabel {color: yellow};");
        ui->yellow->show();
        ui->black->setText("50 to 60");
        ui->black->setStyleSheet("QLabel {color: black};");
        ui->black->show();
    }
    else if(ui->statistic_data->currentText()=="gender")
    {
        ui->statistics_lab->clear();
        ui->statistics_lab->hide();
        e=new(employee);
        e->select_gender();
        ui->statistics->hide();

        ui->statistics->insert_values(2, e->Get_females(), e->Get_males());
        ui->red->show();
        ui->yellow->hide();
        ui->black->hide();
        ui->green->hide();
        ui->red->setText("females");
        ui->red->setStyleSheet("QLabel {color:red};");
        ui->statistics->show();
        ui->blue->setStyleSheet("QLabel {color: blue};");
        ui->blue->show();
        ui->blue->setText("males");

    }
    else if(ui->statistic_data->currentText()=="employee_groupe")
    {
        ui->statistics_lab->clear();
        ui->statistics_lab->hide();
        e=new(employee);
        e->select_posts();
        ui->statistics->hide();
        ui->statistics->insert_values(5, e->Get_interveiwers(), e->Get_managers(), e->Get_drivers(), e->Get_sellers(), e->Get_inventory_staff());
        ui->statistics->show();
        ui->red->setText("interveiwers");
        ui->red->setStyleSheet("QLabel {color:red};");
        ui->red->show();
        ui->blue->setText("managers");
        ui->blue->setStyleSheet("QLabel {color: blue};");
        ui->blue->show();
        ui->green->setText("drivers");
        ui->green->setStyleSheet("QLabel {color:green};");
        ui->green->show();
        ui->yellow->setText("sellers");
        ui->yellow->setStyleSheet("QLabel {color: yellow};");
        ui->yellow->show();
        ui->black->setText("inventory staff");
        ui->black->setStyleSheet("QLabel {color: black};");
        ui->black->show();


    }
    else
    {
        ui->statistics_lab->setText("please specify an option");
        ui->statistics_lab->setStyleSheet("QLabel { color: red } ;");
    }
}

void gestionrh::on_graph_data_currentIndexChanged()
{

    e=new employee();
    if(ui->graph_data->currentText()=="age")
    {
        ui->graph_error->hide();
        ui->histograph->close();
        e->select_ages();
        ui->histograph->insert_values(5, e->Get_male_adults_18_25()+e->Get_female_adults_18_25(), e->Get_male_adults_25_30()+e->Get_female_adults_25_30(), e->Get_male_adults_30_40()+e->Get_female_adults_30_40(), e->Get_male_adults_40_50()+e->Get_female_adults_40_50(), e->Get_male_adults_60_50()+e->Get_female_adults_60_50());
        hide_graph_titels();
        ui->histograph->show();
        ui->red_graph->setText("18 to 25");
        ui->red_graph->show();
        ui->blue_graph->setText("25 to 30");
        ui->blue_graph->show();
        ui->green_graph->setText("30 to 40");
        ui->green_graph->show();
        ui->yellow_graph->setText("40 to 50");
        ui->yellow_graph->show();
        ui->black_graph->setText("50 to 60");
        ui->black_graph->show();

    }
    else if(ui->graph_data->currentText()=="gender")
    {
        hide_graph_titels();
        ui->graph_error->hide();
        ui->histograph->close();
        ui->green_graph->hide();
        ui->black_graph->hide();
        ui->yellow_graph->hide();
        e->select_gender();
        ui->histograph->insert_values(2, e->Get_males(), e->Get_females());
        ui->histograph->show();
        ui->red_graph->setText("males");
        ui->red_graph->show();
        ui->blue_graph->setText("females");
        ui->blue_graph->show();

    }
    else if(ui->graph_data->currentText()=="employee_groupe")
    {
        ui->graph_error->hide();

        ui->histograph->close();
        e->select_posts();
        ui->histograph->insert_values(5, e->Get_interveiwers(), e->Get_managers(), e->Get_drivers(), e->Get_sellers(), e->Get_inventory_staff());
        ui->histograph->show();
        hide_graph_titels();
        ui->red_graph->setText("interveiwer");
        ui->red_graph->show();
        ui->blue_graph->setText("managers");
        ui->blue_graph->show();
        ui->green_graph->setText("drivers");
        ui->green_graph->show();
        ui->yellow_graph->setText("sellers");
        ui->yellow_graph->show();
        ui->black_graph->setText("inventory staff");
        ui->black_graph->show();

    }
    else
    {
        ui->graph_error->setText("specify data to display please");
        ui->graph_error->setStyleSheet("QLabel{color: red };");
        ui->graph_error->show();

    }
}


void  gestionrh::set_graph_header_data(int max)
{
    QString  line="---------";
    if(max<=5)
    {
        ui->one_graph->setText("1"+line);
        ui->three_graph->setText("2"+line);
        ui->five_graph->setText("3"+line);
        ui->seven_graph->setText("4"+line);
        ui->nine_graph->setText("5"+line);
    }



}
void gestionrh::on_Employe_groupe_currentIndexChanged()
{
    update_table_view();

}


void gestionrh::on_mod_prom_id_employee_currentTextChanged(const QString &arg1)
{
    e=new employee();

    e->select_employee(arg1.toInt());

    ui->mod_prom_current_post_le->setText(e->Get_post());

    ui->mod_prom_emp_name_le->setText(e->Get_name());

    ui->mod_prom_emp_family_name_le->setText(e->Get_lastname());

    QPixmap pixm(e->Get_photo());
    QPixmap mypixmap=pixm.scaled(ui->mod_prom_emp_photo_pix_map->width(),ui->mod_prom_emp_photo_pix_map->height());

    ui->mod_prom_emp_photo_pix_map->setPixmap(mypixmap);

    ui->mod_salary_emp_le->setText(QString::number(e->Get_salary()));

    ui->mod_prom_contract_emp_le->setText(e->Get_contract_type());

    ui->mod_prom_paiment_emp_le->setText(e->Get_paiment_type());
    /*------- calculating salarys---------*/
    calculate_promotion_salary();




}
void gestionrh::calculate_promotion_salary()
{
    QString value=ui->mod_prom_Salary_bonus_sp->text();
    value.replace("%","0");


    double bonus=value.toDouble();
    double new_salary=ui->mod_salary_emp_le->text().toDouble()+ui->mod_salary_emp_le->text().toDouble()*(bonus/1000);
    ui->mod_salary_emp_name_le->setText(QString::number(new_salary));

}

void gestionrh::on_mod_prom_Salary_bonus_sp_editingFinished()
{
    calculate_promotion_salary();
}

void gestionrh::on_mod_prom_Salary_bonus_sp_valueChanged()
{
    calculate_promotion_salary();
}

void gestionrh::on_mod_prom_foreign_post_com_currentTextChanged(const QString &arg1)
{
    bool status;
    if(arg1=="driver")

    {
        status=true;

        ui->mod_prom_yes->setEnabled(status);

        ui->mod_prom_yes_2->setEnabled(status);

        ui->mod_prom_driver_lisence->setEnabled(status);

        ui->mod_prom_days_led->setEnabled(status);

        ui->mod_prom_months_led->setEnabled(status);

        ui->mod_prom_years_led->setEnabled(status);

        status=false;

        ui->mod_prom_e_mail->setEnabled(status);

        ui->mod_prom_type->setEnabled(status);
    }
    else if (arg1=="manager")
    {
        status=true;

        ui->mod_prom_e_mail->setEnabled(status);

        ui->mod_prom_type->setEnabled(status);

        status=false;

        ui->mod_prom_yes->setEnabled(status);

        ui->mod_prom_yes_2->setEnabled(status);

        ui->mod_prom_driver_lisence->setEnabled(status);

        ui->mod_prom_days_led->setEnabled(status);

        ui->mod_prom_months_led->setEnabled(status);

        ui->mod_prom_years_led->setEnabled(status);

    }
    else
    {

        status=false;

        ui->mod_prom_e_mail->setEnabled(status);

        ui->mod_prom_type->setEnabled(status);

        ui->mod_prom_yes->setEnabled(status);

        ui->mod_prom_yes_2->setEnabled(status);

        ui->mod_prom_driver_lisence->setEnabled(status);

        ui->mod_prom_days_led->setEnabled(status);

        ui->mod_prom_months_led->setEnabled(status);

        ui->mod_prom_years_led->setEnabled(status);

    }
}

void gestionrh::on_Ch_b_contract_method_stateChanged()
{
    if(ui->Ch_b_contract_method->isChecked())
    {
        ui->mod_prom_contract_cb->setCurrentText(ui->mod_prom_contract_emp_le->text());
        ui->mod_prom_contract_cb->setEnabled(false);
    }
    else
    {
        ui->mod_prom_contract_cb->setCurrentIndex(0);
        ui->mod_prom_contract_cb->setEnabled(true);
    }
}

void gestionrh::on_Ch_b_mod_prom_p_m_stateChanged()
{
    if(ui->Ch_b_mod_prom_p_m->isChecked())
    {
        ui->mod_prom_paiment_cb->setCurrentText(ui->mod_prom_paiment_emp_le->text());
        ui->mod_prom_paiment_cb->setEnabled(false);
    }
    else
    {
        ui->mod_prom_paiment_cb->setCurrentIndex(0);
        ui->mod_prom_paiment_cb->setEnabled(true);
    }
}
void gestionrh::hide_promotions_alert_labels()
{
    ui->mod_prom_driver_serial->hide();
    ui->mod_prom_driver_l_ex_d->hide();
    ui->mod_prom_small_trucks_l->hide();
    ui->mod_prom_big_trucks_l->hide();
    ui->mod_prom_type_l->hide();
    ui->mod_prom_email_l->hide();
    ui->mod_prom_new_post_lab->hide();
    ui->mod_prom_salary_alert_lab->hide();
    ui->mod_prom_type_c_l->hide();
    ui->mod_prom_type_p_l->hide();
}

void gestionrh::reset_pomotions_labels_and_combos()
{
    ui->mod_prom_foreign_post_com->setCurrentIndex(0);
    ui->mod_prom_Salary_bonus_sp->clear();
    ui->mod_prom_Salary_bonus_sp->setValue(0);
    calculate_promotion_salary();
    ui->mod_prom_contract_cb->setCurrentIndex(0);
    ui->mod_prom_paiment_cb->setCurrentIndex(0);
    ui->mod_prom_type->setCurrentIndex(0);
    ui->mod_prom_e_mail->clear();
    ui->mod_prom_yes->setChecked(false);
    ui->mod_prom_yes_2->setChecked(false);
    ui->mod_prom_days_led->setCurrentIndex(0);
    ui->mod_prom_months_led->setCurrentIndex(0);
    ui->mod_prom_years_led->setCurrentIndex(0);
    ui->mod_prom_driver_lisence->clear();


}

void gestionrh::connect_slots_with_header_signal()
{
    connect(ui->employee_list->horizontalHeader(), SIGNAL(sectionClicked(int)),this, SLOT(i_exist(int)));

}

void gestionrh::manage_vacations_end_dates()
{
    int month ;
    int year ;
    inputcontrol p;
    QString dataa;

    month=ui->vac_end_months->currentIndex();
    year=ui->vac_end_years->currentText().toInt();

    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        int pos=ui->vac_end_days->currentIndex();
        int i;
        ui->vac_end_days->clear();
        ui->vac_end_days->insertItem(0,"days");

        for( i=1; i<=31; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->vac_end_days->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->vac_end_days->setCurrentIndex(31);
        }
        else
        {
            ui->vac_end_days->setCurrentIndex(pos);
        }
    }
    if(month==2&&p.is_leap_year(year))
    {
        int pos=ui->vac_end_days->currentIndex();
        int i;
        ui->vac_end_days->clear();
        ui->vac_end_days->insertItem(0,"days");

        for( i=1; i<=29; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->vac_end_days->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->vac_end_days->setCurrentIndex(29);
        }
        else
        {
            ui->vac_end_days->setCurrentIndex(pos);
        }
    }
    if(month==2&&p.is_leap_year(year)==false)
    {
        int pos=ui->vac_end_days->currentIndex();
        int i;
        ui->vac_end_days->clear();
        ui->vac_end_days->insertItem(0,"days");
        for( i=1; i<=28; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->vac_end_days->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->vac_end_days->setCurrentIndex(28);
        }
        else
        {
            ui->vac_end_days->setCurrentIndex(pos);
        }
    }
    if(month==4||month==6||month==11||month==9)
    {
        int pos=ui->vac_end_days->currentIndex();
        int i;
        ui->vac_end_days->clear();
        ui->vac_end_days->insertItem(0,"days");
        for( i=1; i<=30; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->vac_end_days->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->vac_end_days->setCurrentIndex(30);
        }
        else
        {
            ui->vac_end_days->setCurrentIndex(pos);
        }
    }
}

void gestionrh::manage_mod_vacations_start_dates()
{
    int month ;
    int year ;
    inputcontrol p;
    QString dataa;
    month=ui->mod_vac_start_months->currentText().toInt();
    year=ui->mod_vac_start_years->currentText().toInt();
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        int pos=ui->mod_vac_start_days->currentIndex();
        int i;
        ui->mod_vac_start_days->clear();
        ui->mod_vac_start_days->insertItem(0,"days");

        for( i=1; i<=31; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->mod_vac_start_days->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->mod_vac_start_days->setCurrentIndex(31);
        }
        else
        {
            ui->mod_vac_start_days->setCurrentIndex(pos);
        }
    }
    if(month==2&&p.is_leap_year(year))
    {
        int pos=ui->mod_vac_start_days->currentIndex();
        int i;
        ui->mod_vac_start_days->clear();
        ui->mod_vac_start_days->insertItem(0,"days");

        for( i=1; i<=29; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->mod_vac_start_days->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->mod_vac_start_days->setCurrentIndex(29);
        }
        else
        {
            ui->mod_vac_start_days->setCurrentIndex(pos);
        }
    }
    if(month==2&&p.is_leap_year(year)==false)
    {
        int pos=ui->mod_vac_start_days->currentIndex();
        int i;
        ui->mod_vac_start_days->clear();
        ui->mod_vac_start_days->insertItem(0,"days");
        for( i=1; i<=28; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->mod_vac_start_days->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->mod_vac_start_days->setCurrentIndex(28);
        }
        else
        {
            ui->mod_vac_start_days->setCurrentIndex(pos);
        }
    }
    if(month==4||month==6||month==11||month==9)
    {
        int pos=ui->mod_vac_start_days->currentIndex();
        int i;
        ui->mod_vac_start_days->clear();
        ui->mod_vac_start_days->insertItem(0,"days");
        for( i=1; i<=30; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->mod_vac_start_days->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->mod_vac_start_days->setCurrentIndex(30);
        }
        else
        {
            ui->mod_vac_start_days->setCurrentIndex(pos);
        }
    }
}

void gestionrh::manage_mod_vacations_end_dates()
{
    int month ;
    int year ;
    inputcontrol p;
    QString dataa;

    month=ui->vac_end_months->currentIndex();
    year=ui->vac_end_years->currentText().toInt();

    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        int pos=ui->mod_vac_end_days->currentIndex();
        int i;
        ui->mod_vac_end_days->clear();
        ui->mod_vac_end_days->insertItem(0,"days");

        for( i=1; i<=31; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->mod_vac_end_days->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->mod_vac_end_days->setCurrentIndex(31);
        }
        else
        {
            ui->mod_vac_end_days->setCurrentIndex(pos);
        }
    }
    if(month==2&&p.is_leap_year(year))
    {
        int pos=ui->mod_vac_end_days->currentIndex();
        int i;
        ui->mod_vac_end_days->clear();
        ui->mod_vac_end_days->insertItem(0,"days");

        for( i=1; i<=29; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->mod_vac_end_days->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->mod_vac_end_days->setCurrentIndex(29);
        }
        else
        {
            ui->mod_vac_end_days->setCurrentIndex(pos);
        }
    }
    if(month==2&&p.is_leap_year(year)==false)
    {
        int pos=ui->mod_vac_end_days->currentIndex();
        int i;
        ui->mod_vac_end_days->clear();
        ui->mod_vac_end_days->insertItem(0,"days");
        for( i=1; i<=28; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->mod_vac_end_days->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->mod_vac_end_days->setCurrentIndex(28);
        }
        else
        {
            ui->mod_vac_end_days->setCurrentIndex(pos);
        }
    }
    if(month==4||month==6||month==11||month==9)
    {
        int pos=ui->mod_vac_end_days->currentIndex();
        int i;
        ui->mod_vac_end_days->clear();
        ui->mod_vac_end_days->insertItem(0,"days");
        for( i=1; i<=30; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->mod_vac_end_days->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->mod_vac_end_days->setCurrentIndex(30);
        }
        else
        {
            ui->mod_vac_end_days->setCurrentIndex(pos);
        }
    }
}

void gestionrh::manager_vacation_start_dates()
{
    int month ;
    int year ;
    inputcontrol p;
    QString dataa;
    month=ui->vac_start_months->currentIndex();
    year=ui->vac_start_years->currentText().toInt();

    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        int pos=ui->vac_start_days->currentIndex();
        int i;
        ui->vac_start_days->clear();
        ui->vac_start_days->insertItem(0,"days");

        for( i=1; i<=31; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->vac_start_days->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->vac_start_days->setCurrentIndex(31);
        }
        else
        {
            ui->vac_start_days->setCurrentIndex(pos);
        }
    }
    if(month==2&&p.is_leap_year(year))
    {
        int pos=ui->vac_start_days->currentIndex();
        int i;
        ui->vac_start_days->clear();
        ui->vac_start_days->insertItem(0,"days");

        for( i=1; i<=29; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->vac_start_days->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->vac_start_days->setCurrentIndex(29);
        }
        else
        {
            ui->vac_start_days->setCurrentIndex(pos);
        }
    }
    if(month==2&&p.is_leap_year(year)==false)
    {
        int pos=ui->vac_start_days->currentIndex();
        int i;
        ui->vac_start_days->clear();
        ui->vac_start_days->insertItem(0,"days");
        for( i=1; i<=28; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->vac_start_days->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->vac_start_days->setCurrentIndex(28);
        }
        else
        {
            ui->vac_start_days->setCurrentIndex(pos);
        }
    }
    if(month==4||month==6||month==11||month==9)
    {
        int pos=ui->vac_start_days->currentIndex();
        int i;
        ui->vac_start_days->clear();
        ui->vac_start_days->insertItem(0,"days");
        for( i=1; i<=30; i++)
        {
            if(i<=9)
            {
                dataa="0"+QString::number(i);
            }
            else
            {
                dataa=QString::number(i);
            }
            ui->vac_start_days->insertItem(i,dataa);
        }
        if(pos>i)
        {
            ui->vac_start_days->setCurrentIndex(30);
        }
        else
        {
            ui->vac_start_days->setCurrentIndex(pos);
        }
    }
}

void gestionrh::insert_raises_combobx_data()
{
    r= new raises() ;
    ui->id_raise->setModel(r->select_all_raises_ids());
    delete r;
}

void gestionrh::load_history_urls()
{
    /* load history */
}



void gestionrh::randomise_shifts()
{
    for(int i=1;i<=7;i++)
    {
        time_t t;
        int number ;
        qsrand((unsigned) time(&t));
        number=qrand()%7+i;
        qDebug()<<number;

    }
}

void gestionrh::manage_schedule(QDate week_start_day, int day_of_week)
{

    /*----- restting ----*/
    ui->monday_morning_pb->setDisabled(false);
    ui->monday_after_noon_pb->setDisabled(false);
    ui->tuesday_morning_pb->setDisabled(false);
    ui->tuesday_after_noon_pb->setDisabled(false);
    ui->wednsday_morning_pb->setDisabled(false);
    ui->wednsday_after_noon_pb->setDisabled(false);
    ui->thursday_morning_pb->setDisabled(false);
    ui->thursday_after_noon_pb->setDisabled(false);
    ui->friday_morning_pb->setDisabled(false);
    ui->friday_after_noon_pb->setDisabled(false);
    ui->saturday_morning_pb->setDisabled(false);
    ui->saturday_after_noon_pb->setDisabled(false);

    /*------- line edits ------*/
    ui->shift_monday_morning_nbr_places->setDisabled(false);
    ui->shift_monday_after_noon_nbr_places->setDisabled(false);
    ui->shift_tuesday_morning_nbr_places->setDisabled(false);
    ui->shift_tuesday_after_noon_nbr_places->setDisabled(false);
    ui->shift_wednsday_morning_nbr_places->setDisabled(false);
    ui->shift_wednsday_after_noon_nbr_places->setDisabled(false);
    ui->shift_thursday_nbr_places->setDisabled(false);
    ui->shifts_thursday_after_noon->setDisabled(false);
    ui->shift_friday_nbr_places->setDisabled(false);
    ui->shits_afternoon_friday->setDisabled(false);
    ui->shift_saturday_nbr_places->setDisabled(false);
    ui->saturday_after_noon_shifts->setDisabled(false);

    /*------- buttons styls ------*/
    ui->tuesday_morning_pb->setStyleSheet("QPushButton{ background-color : green};");
    ui->tuesday_after_noon_pb->setStyleSheet("QPushButton{ background-color : green};");
    ui->monday_morning_pb->setStyleSheet("QPushButton{ background-color : green};");
    ui->monday_after_noon_pb->setStyleSheet("QPushButton{ background-color : green};");
    ui->wednsday_morning_pb->setStyleSheet("QPushButton{ background-color : green};");
    ui->wednsday_after_noon_pb->setStyleSheet("QPushButton{ background-color : green};");
    ui->thursday_morning_pb->setStyleSheet("QPushButton{ background-color : green};");
    ui->thursday_after_noon_pb->setStyleSheet("QPushButton{ background-color : green};");
    ui->friday_morning_pb->setStyleSheet("QPushButton{ background-color : green};");
    ui->friday_after_noon_pb->setStyleSheet("QPushButton{ background-color : green};");
    ui->saturday_morning_pb->setStyleSheet("QPushButton{ background-color : green};");
    ui->saturday_after_noon_pb->setStyleSheet("QPushButton{ background-color : green};");
    /*switching ---- */
    qDebug()<<"starting case swtiching :..."<<endl;
    qDebug()<<week_start_day<<endl;
    qDebug()<<"the calculated date is"<<QDate::currentDate();//.addDays(-day_of_week+1)
    if(week_start_day==QDate::currentDate())
    {
        switch (day_of_week)
        {qDebug()<<"i got in ! ";
        case 1:
            /*---------buttons -------*/
            ui->monday_morning_pb->setDisabled(true);
            ui->monday_after_noon_pb->setDisabled(true);
            /*------- line edits ------*/
            ui->shift_monday_morning_nbr_places->setDisabled(true);
            ui->shift_monday_after_noon_nbr_places->setDisabled(true);
            /*------- buttons styls ------*/
            ui->monday_morning_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->monday_after_noon_pb->setStyleSheet("QPushButton{ background-color : black};");

            break;
        case 2:
            /*---------buttons -------*/
            ui->monday_morning_pb->setDisabled(true);
            ui->monday_after_noon_pb->setDisabled(true);
            ui->shift_monday_morning_nbr_places->setDisabled(true);
            ui->shift_monday_after_noon_nbr_places->setDisabled(true);
            /*------- line edits ------*/
            ui->shift_tuesday_morning_nbr_places->setDisabled(true);
            ui->shift_tuesday_after_noon_nbr_places->setDisabled(true);
            ui->tuesday_morning_pb->setDisabled(true);
            ui->tuesday_after_noon_pb->setDisabled(true);
            /*------- buttons styls ------*/
            ui->tuesday_morning_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->tuesday_after_noon_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->monday_morning_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->monday_after_noon_pb->setStyleSheet("QPushButton{ background-color : black};");

            break;
        case 3:
            /*---------buttons -------*/
            ui->monday_morning_pb->setDisabled(true);
            ui->monday_after_noon_pb->setDisabled(true);
            ui->tuesday_morning_pb->setDisabled(true);
            ui->tuesday_after_noon_pb->setDisabled(true);
            ui->wednsday_morning_pb->setDisabled(true);
            ui->wednsday_after_noon_pb->setDisabled(true);
            /*------- line edits ------*/
            ui->shift_monday_morning_nbr_places->setDisabled(true);
            ui->shift_monday_after_noon_nbr_places->setDisabled(true);
            ui->shift_tuesday_morning_nbr_places->setDisabled(true);
            ui->shift_tuesday_after_noon_nbr_places->setDisabled(true);
            ui->shift_wednsday_morning_nbr_places->setDisabled(true);
            ui->shift_wednsday_after_noon_nbr_places->setDisabled(true);
            /*------- buttons styls ------*/
            ui->tuesday_morning_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->tuesday_after_noon_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->monday_morning_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->monday_after_noon_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->wednsday_morning_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->wednsday_after_noon_pb->setStyleSheet("QPushButton{ background-color : black};");

            break;
        case 4:
            ui->monday_morning_pb->setDisabled(true);
            ui->monday_after_noon_pb->setDisabled(true);
            ui->tuesday_morning_pb->setDisabled(true);
            ui->tuesday_after_noon_pb->setDisabled(true);
            ui->wednsday_morning_pb->setDisabled(true);
            ui->wednsday_after_noon_pb->setDisabled(true);
            ui->thursday_morning_pb->setDisabled(true);
            ui->thursday_after_noon_pb->setDisabled(true);
            /*------- line edits ------*/
            ui->shift_monday_morning_nbr_places->setDisabled(true);
            ui->shift_monday_after_noon_nbr_places->setDisabled(true);
            ui->shift_tuesday_morning_nbr_places->setDisabled(true);
            ui->shift_tuesday_after_noon_nbr_places->setDisabled(true);
            ui->shift_wednsday_morning_nbr_places->setDisabled(true);
            ui->shift_wednsday_after_noon_nbr_places->setDisabled(true);
            ui->shift_thursday_nbr_places->setDisabled(true);
            ui->shifts_thursday_after_noon->setDisabled(true);

            /*------- buttons styls ------*/
            ui->tuesday_morning_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->tuesday_after_noon_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->monday_morning_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->monday_after_noon_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->wednsday_morning_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->wednsday_after_noon_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->thursday_morning_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->thursday_after_noon_pb->setStyleSheet("QPushButton{ background-color : black};");
            break;
        case 5:
            ui->monday_morning_pb->setDisabled(true);
            ui->monday_after_noon_pb->setDisabled(true);
            ui->tuesday_morning_pb->setDisabled(true);
            ui->tuesday_after_noon_pb->setDisabled(true);
            ui->wednsday_morning_pb->setDisabled(true);
            ui->wednsday_after_noon_pb->setDisabled(true);
            ui->thursday_morning_pb->setDisabled(true);
            ui->thursday_after_noon_pb->setDisabled(true);
            ui->friday_morning_pb->setDisabled(true);
            ui->friday_after_noon_pb->setDisabled(true);
            /*------- line edits ------*/
            ui->shift_monday_morning_nbr_places->setDisabled(true);
            ui->shift_monday_after_noon_nbr_places->setDisabled(true);
            ui->shift_tuesday_morning_nbr_places->setDisabled(true);
            ui->shift_tuesday_after_noon_nbr_places->setDisabled(true);
            ui->shift_wednsday_morning_nbr_places->setDisabled(true);
            ui->shift_wednsday_after_noon_nbr_places->setDisabled(true);
            ui->shift_thursday_nbr_places->setDisabled(true);
            ui->shifts_thursday_after_noon->setDisabled(true);
            ui->shift_friday_nbr_places->setDisabled(true);
            ui->shits_afternoon_friday->setDisabled(true);

            /*------- buttons styls ------*/
            ui->tuesday_morning_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->tuesday_after_noon_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->monday_morning_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->monday_after_noon_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->wednsday_morning_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->wednsday_after_noon_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->thursday_morning_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->thursday_after_noon_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->friday_morning_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->friday_after_noon_pb->setStyleSheet("QPushButton{ background-color : black};");

            break;
        case 6:
            ui->monday_morning_pb->setDisabled(true);
            ui->monday_after_noon_pb->setDisabled(true);
            ui->tuesday_morning_pb->setDisabled(true);
            ui->tuesday_after_noon_pb->setDisabled(true);
            ui->wednsday_morning_pb->setDisabled(true);
            ui->wednsday_after_noon_pb->setDisabled(true);
            ui->thursday_morning_pb->setDisabled(true);
            ui->thursday_after_noon_pb->setDisabled(true);
            ui->friday_morning_pb->setDisabled(true);
            ui->friday_after_noon_pb->setDisabled(true);
            ui->saturday_morning_pb->setDisabled(true);
            ui->saturday_after_noon_pb->setDisabled(true);

            /*------- line edits ------*/
            ui->shift_monday_morning_nbr_places->setDisabled(true);
            ui->shift_monday_after_noon_nbr_places->setDisabled(true);
            ui->shift_tuesday_morning_nbr_places->setDisabled(true);
            ui->shift_tuesday_after_noon_nbr_places->setDisabled(true);
            ui->shift_wednsday_morning_nbr_places->setDisabled(true);
            ui->shift_wednsday_after_noon_nbr_places->setDisabled(true);
            ui->shift_thursday_nbr_places->setDisabled(true);
            ui->shifts_thursday_after_noon->setDisabled(true);
            ui->shift_friday_nbr_places->setDisabled(true);
            ui->shits_afternoon_friday->setDisabled(true);
            ui->shift_saturday_nbr_places->setDisabled(true);
            ui->saturday_after_noon_shifts->setDisabled(true);

            /*------- buttons styls ------*/
            ui->tuesday_morning_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->tuesday_after_noon_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->monday_morning_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->monday_after_noon_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->wednsday_morning_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->wednsday_after_noon_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->thursday_morning_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->thursday_after_noon_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->friday_morning_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->friday_after_noon_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->saturday_morning_pb->setStyleSheet("QPushButton{ background-color : black};");
            ui->saturday_after_noon_pb->setStyleSheet("QPushButton{ background-color : black};");
            break;
        default:
            if(day_of_week==7)
            {
                day_of_week=0;
            }
        }
    }



}

void gestionrh::on_c_clicked()
{
    hide_promotions_alert_labels();
    reset_pomotions_labels_and_combos();
}



void gestionrh::i_exist(int pos)
{
    QString order;
    e=new employee();

    int value= ui->employee_list->horizontalHeader()->sortIndicatorOrder();
    if(value==0)
    {
        order="ASC";
    }
    else if(value==1)
    {
        order="DESC";
    }
    ui->employee_list->setModel(e->employee_list(ui->search_employee->text(),ui->Employe_groupe->currentText(),pos,order));
    delete e;

}

void gestionrh::on_promote_emp_clicked()
{


    hide_promotions_alert_labels();

    if(is_promotion_data_existant_and_valid()==true)
    {
        original_p=ui->mod_prom_current_post_le->text();
        foreign_p=ui->mod_prom_foreign_post_com->currentText();
        bonus_salary=ui->mod_salary_emp_name_le->text().toDouble();
        promotion_holder=ui->mod_prom_id_employee->currentText().toInt();
        if(QMessageBox::warning(0,"Hamadi ERP","by clicking yes you are updating this employee","yes","no i changed my mind")==0)
        {
            if(foreign_p=="manager")
            {
                e=new employee();
                e->select_employee(ui->mod_prom_id_employee->currentText().toInt());
                m=new manager(e->Get_name(),ui->mod_prom_type->currentText(),ui->mod_prom_e_mail->text());
                qDebug()<< "updateing manager table";
                m->this_employee_became_a_manager(ui->mod_prom_id_employee->currentText().toInt());

                delete m;
                delete e;
            }
            else if(foreign_p=="driver")
            {
                e=new employee();
                e->select_employee(ui->mod_prom_id_employee->currentText().toInt());
                int y=ui->mod_prom_years_led->currentText().toInt();
                int m=ui->mod_prom_months_led->currentText().toInt();
                int d=ui->mod_prom_days_led->currentText().toInt();
                QDate exp_date(y,m,d);

                this-> d=new driver(ui->mod_prom_driver_lisence->text().toInt(),ui->mod_prom_yes_2->checkState(),ui->mod_prom_yes->checkState(),exp_date);
                qDebug()<< "updateing driver table";
                this-> d->this_employee_became_a_driver(ui->mod_prom_id_employee->currentText().toInt());

                delete this->d;
                delete e;
            }
            /*insert items into promotion instence and call the update function
            for employee then add the promotion into the data base*/
            p=new promotion(original_p,foreign_p,bonus_salary,promotion_holder);
            qDebug()<< "adding promotion...";
            if(p->add_promotion())

            {
                e=new() employee(foreign_p,bonus_salary,ui->mod_prom_contract_cb->currentText(),ui->mod_prom_paiment_cb->currentText());
                qDebug()<<"promoting employee...";
                e->promote_employee(ui->mod_prom_id_employee->currentText().toInt());

                QMessageBox::information(0,"Hamadi ERP","employee promoted with success",QMessageBox::Ok);
                update_table_view();
                insert_employee_combobox_data();
                insert_employee_data();

            }
            else
            {
                QMessageBox::critical(0,"Hamadi ERP","something broke ",QMessageBox::Ok);
            }
        }

        else
        {
            QMessageBox::critical(0,"Hamadi ERP","the data you entred seems unvalid ",QMessageBox::Ok);
        }
    }
    else
    {
        /* do nothing */
    }

}

void gestionrh::on_promotion_history_tab_v_doubleClicked(const QModelIndex &index)
{
    int pos = index.row();
    QString id=ui->promotion_history_tab_v->model()->data(ui->promotion_history_tab_v->model()->index(pos,0)).toString();
    ui->mod_prom_id_employee->setCurrentText(id);

}


void gestionrh::on_mod_prom_search_name_textChanged(const QString &arg1)
{
    e =new employee();
    ui->promotion_history_tab_v->setModel(e->employee_list_with_exception2("driver","manager",arg1));
    ui->promotion_history_tab_v->resizeColumnsToContents();
    ui->promotion_history_tab_v->resizeRowsToContents();
    delete e;
}

void gestionrh::on_mod_move_id_employee_currentTextChanged(const QString &arg1)
{

    e =new employee();
    e->select_employee(arg1.toInt());
    ui->mod_move_emp_name_le->setText(e->Get_name());
    ui->mod_move_emp_family_name_le->setText(e->Get_lastname());
    ui->mod_move_current_post_le->setText(e->Get_post());
    ui->mod_move_contract_emp_le->setText(e->Get_contract_type());
    QPixmap pix(e->Get_photo());
    QPixmap pixmap(pix.scaled(ui->mod_move_emp_photo_pix_map->width(),ui->mod_move_emp_photo_pix_map->height()));
    ui->mod_move_emp_photo_pix_map->setPixmap(pixmap);

}

void gestionrh::on_mod_move_search_name_textChanged(const QString &arg1)
{
    e=new employee();
    ui->mouvement_history_tab_v->setModel(e->employee_list_promotion(arg1));
    ui->mouvement_history_tab_v->resizeColumnsToContents();
    ui->mouvement_history_tab_v->resizeRowsToContents();
    delete e;
}

void gestionrh::on_mouvement_history_tab_v_doubleClicked(const QModelIndex &index)
{
    int row=index.row();
    QString id =ui->mouvement_history_tab_v->model()->data(ui->mouvement_history_tab_v->model()->index(row,0)).toString();
    ui->mod_move_id_employee->setCurrentText(id);

}

void gestionrh::on_mod_move_search_building_textChanged(const QString &arg1)
{
    b =new building ();
    ui->mouvement_building_tb_v->setModel(b->building_list_for_mouvement_transactions(arg1));
    ui->mouvement_building_tb_v->resizeColumnsToContents();
    ui->mouvement_building_tb_v->resizeRowsToContents();
    delete b;
}


void gestionrh::on_move_building_id_com_currentTextChanged(const QString &arg1)
{
    b=new building();
    b->select_building(arg1.toInt());
    ui->move_building_name->setText(b->Get_name());
    ui->move_building_size->setText(b->Get_size());
    ui->move_building_area->setText(b->Get_area());
    ui->move_building_city->setText(b->Get_city());
    ui->move_building_street->setText(b->Get_street());
    ui->move_building_zip_code->setText(b->Get_zip_code());
    ui->move_building_capacity->setText(QString::number(b->Get_max_employee_capacity()));
    ui->move_building_type->setText(b->Get_type());
    int places =b->Get_max_employee_capacity()-b->how_much_space_is_left_in_this_building(arg1.toInt());
    ui->move_building_places_left->setText(QString::number(places));
    delete b ;
}

void gestionrh::on_move_building_places_left_textChanged(const QString &arg1)
{
    if(arg1.toInt()>=10)
    {
        ui->move_building_places_left->setStyleSheet("QLineEdit { color : green ;background-color: white;}");
    }
    if(arg1.toInt()<10)
    {
        ui->move_building_places_left->setStyleSheet("QLineEdit { color : blue ;background-color: white ;}");
    }
    if(arg1.toInt()<=5)
    {
        ui->move_building_places_left->setStyleSheet("QLineEdit { color : red ;background-color: white; }");
    }
}

void gestionrh::on_clear_mouvement_clicked()
{
    ui->move_description->clear();
    ui->move_Description_l->hide();
    ui-> move_places_left_l->hide();

}

void gestionrh::on_move_employee_clicked()
{

    int res=0;
    ui->move_places_left_l->hide();
    ui->move_Description_l->hide();
    ui->move_id_building_l->hide();
    if(ui->move_building_places_left->text().toInt()==0)
    {
        ui->move_places_left_l->setStyleSheet("QLabel { color : red ;}");

        ui->move_places_left_l->setText("this building seems over occupied ");

        ui->move_places_left_l->show();

        res++;


    }
    if(ui->move_description->toPlainText()=="")
    {
        ui->move_Description_l->setStyleSheet("QLabel { color : red ;}");

        ui->move_Description_l->setText("Description is empty");

        ui->move_Description_l->show();

        res++;
    }
    if(res>0)
    {
        e= new employee();
        e->select_employee(ui->mod_move_id_employee->currentText().toInt());
        if(e->Get_building()==ui->move_building_id_com->currentText().toInt())
        {
            ui->move_id_building_l->setStyleSheet("QLabel { color : red ;}");

            ui->move_id_building_l->setText("you can't move an employee to the same building");

            ui->move_id_building_l->show();
            QMessageBox::critical(0,"System","you haven't specified a target building",QMessageBox::Ok);
        }
        else
        {
            QMessageBox::critical(0,"System","the data you presented cannot be processed",QMessageBox::Ok);
        }
    }
    else
    {
        e=new employee();
        e->select_employee(ui->mod_move_id_employee->currentText().toInt());
        original_building=e->Get_building();
        new_building=ui->move_building_id_com->currentText().toInt();
        description= ui->move_description->toPlainText();
        mou=new mouvement(original_building,new_building,description);
        if(mou->add_mouvement())
        {e->move_employee(ui->mod_move_id_employee->currentText().toInt(),new_building);
            QMessageBox::information(0,"System","employee moved with success",QMessageBox::Ok);
            update_table_view();
            on_move_building_id_com_currentTextChanged(ui->move_building_id_com->currentText());
        }
        else
        {
            QMessageBox::critical(0,"System","something broke",QMessageBox::Ok);
        }
    }


}

void gestionrh::on_mouvement_building_tb_v_doubleClicked(const QModelIndex &index)
{
    int row=index.row();
    QString building = ui->mouvement_building_tb_v->model()->data(ui->mouvement_building_tb_v->model()->index(row,0)).toString();
    ui->move_building_id_com->setCurrentText(building);
}

void gestionrh::on_vac_search_name_textChanged(const QString &arg1)
{
    e=new employee();
    ui->vacation_employee_list_tv->setModel(e->employee_list(arg1,"All employees"));
    ui->vacation_employee_list_tv->resizeColumnsToContents();
    ui->vacation_employee_list_tv->resizeRowsToContents();
    delete e;
}

void gestionrh::on_vacation_employee_list_tv_doubleClicked(const QModelIndex &index)
{
    int row=index.row();
    QString name=ui->vacation_employee_list_tv->model()->data(ui->vacation_employee_list_tv->model()->index(row,0)).toString();
    ui->vac_id_employee->setCurrentText(name);
}

void gestionrh::on_number_of_vacation_days_editingFinished()
{
    /*ending date must change according to a start date and number of days */
    int d,m,y;
    d=ui->vac_start_days->currentText().toInt();
    m=ui->vac_start_months->currentText().toInt();
    y=ui->vac_start_years->currentText().toInt();
    QDate start_date(y,m,d);
    qDebug()<<" initial days :"<<d;
    qDebug()<<" initial months :"<<m;
    qDebug()<<" initial years :"<<y;
    //     QString value=ui->number_of_vacation_days->value();
    //     value.remove("days");
    //     int days=value.toInt();

    int value=ui->number_of_vacation_days->value();
    qDebug()<< "days added :" <<value;
    start_date=start_date.addDays(value);
    qDebug()<<"end days :"<< start_date.day();
    qDebug()<<"end months :"<< start_date.month();
    qDebug()<<"end years :"<< start_date.year();

    ui->vac_end_days->setCurrentIndex(start_date.day());
    ui->vac_end_months->setCurrentIndex(start_date.month());
    ui->vac_end_years->setCurrentText(QString::number(start_date.year()));

}
void gestionrh::on_late_declared_vacation_clicked()
{
    QString state;
    bool continue_work=false ;

    state=ui->late_declared_vacation->text();
    if( QMessageBox::warning(0,"Hamadi ERP"," by clicking yes you are activating \n late vacation mode \n which is not advised ","Yes","No")==0&&state!="disable late vacation mode")
    {
        continue_work=true;
    }

    if(continue_work)
    {
        ui->start_date_vacation_error_lab->hide();
        if(state=="disable late vacation mode")
        {
            ui->late_declared_vacation->setText("enable late vacation mode");
        }
        else if(state=="enable late vacation mode")
        {
            ui->late_declared_vacation->setText("disable late vacation mode");
        }
    }
}
void gestionrh::on_number_of_vacation_days_valueChanged(int arg1)
{
    ui->start_date_vacation_error_lab->hide();
    if(arg1==0)
    {
        ui->number_of_vacation_days->setStyleSheet("QSpinBox { color : red ;background-color: rgba(0,0,0,0); }");
        if(ui->vac_start_days->currentIndex()==0||ui->vac_start_months->currentIndex()==0||ui->vac_start_years->currentIndex()==0)
        {
            ui->start_date_vacation_error_lab->setText("incompleat starting date ");
            ui->start_date_vacation_error_lab->setStyleSheet("QLabel {color : red;}");
            ui->start_date_vacation_error_lab->show();
        }

        else if (ui->vac_start_days->currentIndex()==0&&ui->vac_start_months->currentIndex()==0&&ui->vac_start_years->currentIndex()==0)
        {
            ui->start_date_vacation_error_lab->setText("unspecified starting date ");
            ui->start_date_vacation_error_lab->setStyleSheet("QLabel {color : red;}");
            ui->start_date_vacation_error_lab->show();
        }

    }
    else
    {if(ui->vac_start_days->currentIndex()==0&&ui->vac_start_months->currentIndex()==0&&ui->vac_start_years->currentIndex()==0)
        {
            ui->start_date_vacation_error_lab->setText("unspecified starting date ");
            ui->start_date_vacation_error_lab->setStyleSheet("QLabel {color : red;}");
            ui->start_date_vacation_error_lab->show();
        }
        else if(ui->vac_start_days->currentIndex()==0||ui->vac_start_months->currentIndex()==0||ui->vac_start_years->currentIndex()==0)
        {
            ui->start_date_vacation_error_lab->setText("incompleat starting date ");
            ui->start_date_vacation_error_lab->setStyleSheet("QLabel {color : red;}");
            ui->start_date_vacation_error_lab->show();
        }
        ui->number_of_vacation_days->setStyleSheet("QSpinBox { color : green ;background-color: rgba(0,0,0,0); }");
        on_number_of_vacation_days_editingFinished();
    }



}


void gestionrh::on_vac_end_months_currentTextChanged()
{
    manage_vacations_end_dates();
}

void gestionrh::on_vac_end_years_currentIndexChanged()
{
    manage_vacations_end_dates();
}

void gestionrh::on_vac_start_years_currentIndexChanged()
{
    manager_vacation_start_dates();
    on_number_of_vacation_days_editingFinished();
}

void gestionrh::on_vac_start_months_currentIndexChanged()
{
    manager_vacation_start_dates();
    on_number_of_vacation_days_editingFinished();
}


void gestionrh::on_vac_start_days_currentTextChanged()
{
    on_number_of_vacation_days_editingFinished();
}

void gestionrh::on_enable_or_select_new_raise_clicked()
{
    if(ui->enable_or_select_new_raise->text()=="select existing raise")
    {
        ui->enable_or_select_new_raise->setText("add new raise");
        ui->add_raise->setEnabled(false);
        ui->clear_raise->setEnabled(false);
        ui->amount_raise_sp->setReadOnly(true);
        ui->Raise_title_le->setReadOnly(true);
        ui->id_raise->setEnabled(true);
        on_id_raise_currentTextChanged(ui->id_raise->currentText());



    }
    else if(ui->enable_or_select_new_raise->text()=="add new raise")
    {
        ui->enable_or_select_new_raise->setText("select existing raise");
        ui->add_raise->setEnabled(true);
        ui->clear_raise->setEnabled(true);
        ui->amount_raise_sp->setReadOnly(false);
        ui->Raise_title_le->setReadOnly(false);
        ui->id_raise->setEnabled(false);
        ui->raise_title_error_lab->show();
        on_clear_raise_clicked();



    }


}
void gestionrh::on_clear_raise_clicked()
{

    ui->amount_raise_sp->clear();
    ui->Raise_title_le->clear();
}

void gestionrh::on_add_raise_clicked()
{
    ui->raise_title_error_lab->hide();
    ui->amount_error_lab->hide();
    /*------ data gathering -------*/
    amount=ui->amount_raise_sp->value();
    title=ui->Raise_title_le->text();
    /*------- input control ---------*/
    inputcontrol *test =new inputcontrol();
    int res=0;
    if(amount==0)
    {
        ui->amount_error_lab->setText("the amount you specified is null");
        ui->amount_error_lab->setStyleSheet("QLabel{color :red };");
        ui->amount_error_lab->show();
        res++;
    }

    if(title.isEmpty())

    {
        ui->raise_title_error_lab->setText("empty field");
        ui->raise_title_error_lab->setStyleSheet("QLabel{color :red };");
        ui->raise_title_error_lab->show();
        res++;
    }
    else if (test->is_valid_name(title)==false)
    {
        ui->raise_title_error_lab->setText("unvalid title");
        ui->raise_title_error_lab->setStyleSheet("QLabel{color :blue };");
        ui->raise_title_error_lab->show();
        res++;
    }


    if(res>0)
    {
        QMessageBox::critical(0,"Hamadi ERP","the information you presented cannot be processed ",QMessageBox::Ok);
    }

    else
    {
        r= new raises(title,amount);
        if(r->does_this_raise_already_exist())
        {
            QMessageBox::critical(0,"Hamadi ERP","this raise has been already registred At"+r->Get_date_assigned().toString("dd/MM/yyyy"),QMessageBox::Ok);
        }
        else {

            if( r->create_raise())
            {
                QMessageBox::information(0,"Hamadi ERP","a new raise has been created ",QMessageBox::Ok);
                on_clear_raise_clicked();
                insert_raises_combobx_data();
            }
            else
            {
                QMessageBox::critical(0,"Hamadi ERP","data base runtime error");
            }

        }
    }
}

void gestionrh::on_id_raise_currentTextChanged(const QString &arg1)
{
    if(ui->enable_or_select_new_raise->text()!="select existing raise")
    {
        r= new raises();
        r->select_raise(arg1.toInt());
        ui->amount_raise_sp->setValue(r->Get_amount());
        ui->Raise_title_le->setText(r->Get_title());
        delete r;
    }
}

void gestionrh::on_raise_id_employee_currentTextChanged(const QString &arg1)
{
    e=new employee();
    e->select_employee(arg1.toInt());
    ui->raise_emp_name_le->setText(e->Get_name());
    ui->raise_emp_family_name_le->setText(e->Get_lastname());
    QPixmap pix(e->Get_photo());
    QPixmap scaled_pix=pix.scaled(ui->raise_emp_photo_pix_map->width(),ui->raise_emp_photo_pix_map->height());
    ui->raise_emp_photo_pix_map->setPixmap(scaled_pix);
    ui->raise_current_post_le->setText(e->Get_post());
    ui->raise_contract_emp_le->setText(e->Get_contract_type());
    // delete e;
}

void gestionrh::on_raise_search_name_textChanged(const QString &arg1)
{
    e= new employee ();
    ui-> raise_employee_list_tab_v->setModel(e->employee_list(arg1,"All employees"));
    //delete e ;
}

void gestionrh::on_raise_employee_list_tab_v_doubleClicked(const QModelIndex &index)
{
    int row=index.row();
    ui->raise_id_employee->setCurrentText( ui->raise_employee_list_tab_v->model()->data(ui->raise_employee_list_tab_v->model()->index(row,0)).toString());
}

void gestionrh::on_take_me_back_to_search_clicked()
{
    ui->employee->setCurrentIndex(3);
    ui->Update->setCurrentIndex(0);
    ui->take_me_back_to_search->hide();
}

void gestionrh::on_search_raises_textChanged(const QString &arg1)
{
    r= new raises () ;
    ui->raises_table_view->setModel(r->select_raises(arg1));
    ui->raises_table_view->resizeColumnsToContents();
    ui->raises_table_view->resizeRowsToContents();
    delete r ;
}


void gestionrh::on_go_web_site_clicked()
{
    QString website;

    website= ui->url->currentText();
    if(website.contains("http://"))
    {
        /*do nothing*/
    }
    else if(website.isEmpty())
    {
        /*do nothing*/
    }
    else if (!website.contains("http://"))
    {
        website.push_front("http://");
    }
    if(website.isEmpty())
    {

    }
    else {
        QUrl url(website);
        ui->hamadi_web->load(url);
        history.push_back(url);
        QString var=  history[history.size()-1].toString();
        ui->url->insertItem(history.size()-1,var);
        //  ui->url->setCurrentIndex(history.size()-1);
    }


}

void gestionrh::on_reload_url_clicked()
{
    QUrl url(ui->url->currentText());
    ui->hamadi_web->load(url);
}

void gestionrh::on_next_url_clicked()
{
    if(ui->url->currentIndex()==ui->url->count()-1)
    {
        /*stand by */
    }
    else
    {
        ui->url->setCurrentIndex(ui->url->currentIndex()+1);
        on_reload_url_clicked();
    }
}

void gestionrh::on_last_url_clicked()
{

    if(ui->url->currentIndex()==0)
    {
        /*stand by */
    }
    else
    {
        ui->url->setCurrentIndex(ui->url->currentIndex()-1);
        on_reload_url_clicked();
    }
}

void gestionrh::on_redirect_clicked()
{
    if(ui->url->count()==-1||ui->url->currentText()=="")
    {
        QMessageBox::critical(0,"Hamadi ERP","No url specified to redirect to ...",QMessageBox::Ok);
    }
    else
    {
        QDesktopServices::openUrl(ui->url->currentText());
        setWindowState(Qt::WindowMinimized);
    }

}

void gestionrh::on_url_currentTextChanged()
{
    on_reload_url_clicked();
}

void gestionrh::on_monday_morning_pb_clicked()
{
    QString style =ui->monday_morning_pb->styleSheet();

    if(style=="QPushButton{ background-color : red};")
        ui->monday_morning_pb->setStyleSheet("QPushButton{ background-color : green};");
    else if(style=="QPushButton{ background-color : green};")
    {
        ui->monday_morning_pb->setStyleSheet("QPushButton{ background-color : red};");
    }

}

void gestionrh::on_tuesday_morning_pb_clicked()
{
    QString style =ui->tuesday_morning_pb->styleSheet();

    if(style=="QPushButton{ background-color : red};")
        ui->tuesday_morning_pb->setStyleSheet("QPushButton{ background-color : green};");
    else if(style=="QPushButton{ background-color : green};")
    {
        ui->tuesday_morning_pb->setStyleSheet("QPushButton{ background-color : red};");
    }

}

void gestionrh::on_wednsday_morning_pb_clicked()
{
    QString style =ui->wednsday_morning_pb->styleSheet();

    if(style=="QPushButton{ background-color : red};")
        ui->wednsday_morning_pb->setStyleSheet("QPushButton{ background-color : green};");
    else if(style=="QPushButton{ background-color : green};")
    {
        ui->wednsday_morning_pb->setStyleSheet("QPushButton{ background-color : red};");
    }
}

void gestionrh::on_thursday_morning_pb_clicked()
{
    QString style =ui->thursday_morning_pb->styleSheet();

    if(style=="QPushButton{ background-color : red};")
        ui->thursday_morning_pb->setStyleSheet("QPushButton{ background-color : green};");
    else if(style=="QPushButton{ background-color : green};")
    {
        ui->thursday_morning_pb->setStyleSheet("QPushButton{ background-color : red};");
    }
}

void gestionrh::on_friday_morning_pb_clicked()
{
    QString style =ui->friday_morning_pb->styleSheet();

    if(style=="QPushButton{ background-color : red};")
        ui->friday_morning_pb->setStyleSheet("QPushButton{ background-color : green};");
    else if(style=="QPushButton{ background-color : green};")
    {
        ui->friday_morning_pb->setStyleSheet("QPushButton{ background-color : red};");
    }
}

void gestionrh::on_saturday_morning_pb_clicked()
{
    QString style =ui->saturday_morning_pb->styleSheet();

    if(style=="QPushButton{ background-color : red};")
        ui->saturday_morning_pb->setStyleSheet("QPushButton{ background-color : green};");
    else if(style=="QPushButton{ background-color : green};")
    {
        ui->saturday_morning_pb->setStyleSheet("QPushButton{ background-color : red};");
    }
}

void gestionrh::on_sunday_morning_pb_clicked()
{
    QString style =ui->sunday_morning_pb->styleSheet();

    if(style=="QPushButton{ background-color : red};")
        ui->sunday_morning_pb->setStyleSheet("QPushButton{ background-color : green};");
    else if(style=="QPushButton{ background-color : green};")
    {
        ui->sunday_morning_pb->setStyleSheet("QPushButton{ background-color : red};");
    }
}

void gestionrh::on_sunday_after_noon_pb_clicked()
{
    QString style =ui->sunday_after_noon_pb->styleSheet();

    if(style=="QPushButton{ background-color : red};")
        ui->sunday_after_noon_pb->setStyleSheet("QPushButton{ background-color : green};");
    else if(style=="QPushButton{ background-color : green};")
    {
        ui->sunday_after_noon_pb->setStyleSheet("QPushButton{ background-color : red};");
    }
}

void gestionrh::on_saturday_after_noon_pb_clicked()
{
    QString style =ui->saturday_after_noon_pb->styleSheet();

    if(style=="QPushButton{ background-color : red};")
        ui->saturday_after_noon_pb->setStyleSheet("QPushButton{ background-color : green};");
    else if(style=="QPushButton{ background-color : green};")
    {
        ui->saturday_after_noon_pb->setStyleSheet("QPushButton{ background-color : red};");
    }
}

void gestionrh::on_friday_after_noon_pb_clicked()
{

    QString style =ui->friday_after_noon_pb->styleSheet();

    if(style=="QPushButton{ background-color : red};")
        ui->friday_after_noon_pb->setStyleSheet("QPushButton{ background-color : green};");
    else if(style=="QPushButton{ background-color : green};")
    {
        ui->friday_after_noon_pb->setStyleSheet("QPushButton{ background-color : red};");
    }
}

void gestionrh::on_thursday_after_noon_pb_clicked()
{

    QString style =ui->thursday_after_noon_pb->styleSheet();

    if(style=="QPushButton{ background-color : red};")
        ui->thursday_after_noon_pb->setStyleSheet("QPushButton{ background-color : green};");
    else if(style=="QPushButton{ background-color : green};")
    {
        ui->thursday_after_noon_pb->setStyleSheet("QPushButton{ background-color : red};");
    }
}

void gestionrh::on_wednsday_after_noon_pb_clicked()
{
    QString style =ui->wednsday_after_noon_pb->styleSheet();

    if(style=="QPushButton{ background-color : red};")
        ui->wednsday_after_noon_pb->setStyleSheet("QPushButton{ background-color : green};");
    else if(style=="QPushButton{ background-color : green};")
    {
        ui->wednsday_after_noon_pb->setStyleSheet("QPushButton{ background-color : red};");
    }
}

void gestionrh::on_tuesday_after_noon_pb_clicked()
{

    QString style =ui->tuesday_after_noon_pb->styleSheet();

    if(style=="QPushButton{ background-color : red};")
        ui->tuesday_after_noon_pb->setStyleSheet("QPushButton{ background-color : green};");
    else if(style=="QPushButton{ background-color : green};")
    {
        ui->tuesday_after_noon_pb->setStyleSheet("QPushButton{ background-color : red};");
    }
}

void gestionrh::on_monday_after_noon_pb_clicked()
{
    QString style =ui->monday_after_noon_pb->styleSheet();

    if(style=="QPushButton{ background-color : red};")
        ui->monday_after_noon_pb->setStyleSheet("QPushButton{ background-color : green};");
    else if(style=="QPushButton{ background-color : green};")
    {
        ui->monday_after_noon_pb->setStyleSheet("QPushButton{ background-color : red};");
    }
}

void gestionrh::on_shift_go_clicked()
{
    /*coding started  */

    QString red="QPushButton{ background-color : red};";
    QString green="QPushButton{ background-color : green};";
    qDebug()<<" i am here before vector creation";
    vector<shift>shifts_employee;
    qDebug()<<" vector created with success";
    QString str_date= ui->shift_week->currentText();

    QDate date=QDate::fromString(str_date,"yy,MM,dd");

    int employee ;
    employee= ui->shift_creating_id_employee->currentText().toInt();

    int i=0;
    /*----- data gathering */
    if(ui->monday_morning_pb->styleSheet()==red)
    {qDebug()<<" red monday morning checked";
        shift s("morning","monday",date.addDays(i),employee);
        ss=s;
        shifts_employee.push_back(ss);
    }
    if(ui->tuesday_morning_pb->styleSheet()==red)
    {i++;
        shift s("morning","tuesday",date.addDays(i),employee);
        ss=s;
        shifts_employee.push_back(ss);
    }
    if(ui->wednsday_morning_pb->styleSheet()==red)
    {i++;
        shift s("morning","wednsday",date.addDays(i),employee);
        ss=s;
        shifts_employee.push_back(ss);
    }
    if(ui->thursday_morning_pb->styleSheet()==red)
    {i++;
        shift s("morning","thursday",date.addDays(i),employee);
        ss=s;
        shifts_employee.push_back(ss);
    }
    if(ui->friday_morning_pb->styleSheet()==red)
    {i++;
        shift s("morning","friday",date.addDays(i),employee);
        ss=s;
        shifts_employee.push_back(ss);
    }
    if(ui->saturday_morning_pb->styleSheet()==red)
    {i++;
        shift s("morning","saturday",date.addDays(i),employee);
        ss=s;
        shifts_employee.push_back(ss);
    }
    if(ui->sunday_morning_pb->styleSheet()==red)
    {i++;
        shift s("morning","sunday",date.addDays(i),employee);
        ss=s;
        shifts_employee.push_back(ss);
    }
    if(ui->monday_after_noon_pb->styleSheet()==red)
    {i=0;
        shift s("after noon","monday",date.addDays(i),employee);
        ss=s;
        shifts_employee.push_back(ss);
    }
    if(ui->tuesday_after_noon_pb->styleSheet()==red)
    {i++;
        shift s("after noon","tuesday",date.addDays(i),employee);
        ss=s;
        shifts_employee.push_back(ss);
    }

    if(ui->wednsday_after_noon_pb->styleSheet()==red)
    {i++;
        shift s("after noon","wednsday",date.addDays(i),employee);
        ss=s;
        shifts_employee.push_back(ss);
    }

    if(ui->thursday_after_noon_pb->styleSheet()==red)
    {i++;
        shift s("after noon","thursday",date.addDays(i),employee);
        ss=s;
        shifts_employee.push_back(ss);
    }

    if(ui->friday_after_noon_pb->styleSheet()==red)
    {i++;
        shift s("after noon","friday",date.addDays(i),employee);
        ss=s;
        shifts_employee.push_back(ss);
    }

    if(ui->saturday_after_noon_pb->styleSheet()==red)
    {i++;
        shift s("after noon","saturday",date.addDays(i),employee);
        ss=s;
        shifts_employee.push_back(ss);

    }

    if(ui->sunday_after_noon_pb->styleSheet()==red)
    {i++;
        qDebug()<<" red sunday after noon checked";
        shift s("after noon","sunday",date.addDays(i),employee);
        ss=s;
        shifts_employee.push_back(ss);

    }
    int pb=0;
    for(unsigned int j=0;j<shifts_employee.size();j++)
    {
        if(shifts_employee[j].create_a_shift(j))
        {
            pb++;
        }

    }
    qDebug()<<"shifts executed with "<<pb<<"errors";



}

void gestionrh::on_shift_creating_id_employee_currentTextChanged(const QString &arg1)
{
    e= new employee();
    e->select_employee(arg1.toInt());
    ui->shift_emp_name->setText(e->Get_name()+" "+e->Get_lastname());
    ui->shift_emp_number->setText(QString::number(e->Get_phone_number()));
    QPixmap mypixmap(e->Get_photo());
    QPixmap scaledpixmap=mypixmap.scaled(ui->vac_emp_photo_pix_map->width(),ui->vac_emp_photo_pix_map->height());
    ui->shift_employee_pixm_map->setPixmap(scaledpixmap);

}

void gestionrh::on_shift_week_currentTextChanged(const QString &arg1)
{
    QDate end_date;
    end_date=QDate::fromString(arg1,"dd/MM/yyyy").addDays(6);
    ui->week_end_date->setText(end_date.toString("dd/MM/yyyy"));
    manage_schedule(QDate::fromString(arg1,"dd/MM/yyyy"),QDate::currentDate().dayOfWeek());

}

void gestionrh::on_shifts_employee_list_doubleClicked(const QModelIndex &index)
{
    int pos = index.row();
    QString id=ui->shifts_employee_list->model()->data(ui->shifts_employee_list->model()->index(pos,0)).toString();
    ui->shift_creating_id_employee->setCurrentText(id);
}

void gestionrh::on_search_employee_2_textChanged(const QString &arg1)
{
    ui->shifts_employee_list->setModel(e->employee_list(arg1,"All employees"));
    ui->shifts_employee_list->resizeColumnsToContents();
    ui->shifts_employee_list->resizeRowsToContents();
}

void gestionrh::on_shift_building_list_doubleClicked(const QModelIndex &index)
{
    int pos = index.row();
    QString id=ui->shift_building_list->model()->data(ui->shift_building_list->model()->index(pos,0)).toString();
    ui->move_shift_building_id_com->setCurrentText(id);
}

void gestionrh::on_move_shift_building_id_com_currentTextChanged(const QString &arg1)
{
    b=new building();
    b->select_building(arg1.toInt());
    ui->move_building_name_4->setText(b->Get_name());
    ui->move_building_capacity_4->setText(QString::number(b->Get_max_employee_capacity()));
    ui->move_building_type_4->setText(b->Get_type());
    int places =b->Get_max_employee_capacity()-b->how_much_space_is_left_in_this_building(arg1.toInt());
    ui->move_building_places_left_4->setText(QString::number(places));
    e=new employee();
    ui->shifts_employee_list->setModel(e->employee_list("",ui->move_shift_building_id_com->currentText(),"manager"));
    ui->shift_creating_id_employee->setModel(e->employee_list_shift(ui->move_shift_building_id_com->currentText(),"manager"));
    delete b ;

}

void gestionrh::on_assigne_raise_clicked()
{

    r= new raises();
    if(r->does_this_employee_already_have_this_raise(ui->id_raise->currentText().toInt(),ui->raise_id_employee->currentText().toInt()))
    {
        QMessageBox::critical(0,"Hamadi ERP","This Raise has already been assigned to that employee At :\n"+r->Get_date_assigned().toString("dd/MM/yyyy"),QMessageBox::Ok);
    }
    else
    {
        if( r->assigne_this_raise_to_this_employee(ui->id_raise->currentText().toInt(),ui->raise_id_employee->currentText().toInt()))
        {
            QMessageBox::information(0,"Hamadi ERP","Raise assigned successfully ",QMessageBox::Ok);
        }
        else {
            QMessageBox::critical(0,"Hamadi ERP","something broke ",QMessageBox::Ok);
        }

    }
}

void gestionrh::on_search_raise_update_textChanged(const QString &arg1)
{
    r= new raises ();
    ui->raises_table_update_view->setModel(r->select_raises(arg1));
    ui->raises_table_update_view->resizeColumnsToContents();
    ui->raises_table_update_view->resizeRowsToContents();

}

void gestionrh::on_id_raise_update_currentTextChanged(const QString &arg1)
{
    r= new raises();
    r->select_raise(arg1.toInt());
    ui->amount_raise_sp_update->setValue(r->Get_amount());
    ui->Raise_title_le_update->setText(r->Get_title());
    delete r;
}

void gestionrh::on_raises_table_view_doubleClicked(const QModelIndex &index)
{
    int row=index.row();
    ui->id_raise->setCurrentText( ui->raises_table_view->model()->data(ui->raises_table_view->model()->index(row,0)).toString());
}

void gestionrh::on_raises_table_update_view_doubleClicked(const QModelIndex &index)
{
    int row=index.row();
    ui->id_raise_update->setCurrentText( ui->raises_table_update_view->model()->data(ui->raises_table_update_view->model()->index(row,0)).toString());
}

void gestionrh::on_submit_update_clicked()
{
    if(QMessageBox::warning(0,"Hamadi ERP","By clicking yes you are updating this Raise \n Are you Sure ?","Yes","No")==0)
    {



        r= new raises(ui->Raise_title_le_update->text(), ui->amount_raise_sp_update->value());
        if(r->modify_raise(  ui->id_raise_update->currentText().toInt()))
        {
            QMessageBox::information(0,"Hamadi ERP","Raise Updated with success",QMessageBox::Ok);

        }
        else
        {
            QMessageBox::critical(0,"Hamadi ERP"," Data base time out",QMessageBox::Ok);

        }
    }
    else
    {
        QMessageBox::information(0,"Hamadi ERP"," Update request Canceled",QMessageBox::Ok);
    }

}

void gestionrh::on_update_clear_clicked()
{
    ui->search_raise_update->clear();
    ui->id_raise_update->setCurrentIndex(0);
}

void gestionrh::on_raise_id_employee_reassigne_currentTextChanged(const QString &arg1)
{
    e=new employee();

    e->select_employee(arg1.toInt());

    ui->raise_current_post_le_reassigne->setText(e->Get_post());

    ui->raise_emp_name_le_reassigne->setText(e->Get_name());

    ui->raise_emp_family_name_le_reassigne->setText(e->Get_lastname());

    QPixmap pixm(e->Get_photo());

    QPixmap mypixmap=pixm.scaled(ui->raise_emp_photo_pix_map_reassigne->width(),ui->raise_emp_photo_pix_map_reassigne->height());
    r=new raises ();

    ui->raise_emp_photo_pix_map_reassigne->setPixmap(mypixmap);

    ui->employee_curret_raises_reassigne->setModel(r->select_all_raises_accomplished_by_this_employee(arg1.toInt()));
    ui->employee_curret_raises_reassigne->resizeColumnsToContents();
    ui->employee_curret_raises_reassigne->resizeRowsToContents();
    ui->employee_raises_table_view_reassigne->setModel(r->select_raises(""));
    ui->employee_raises_table_view_reassigne->resizeColumnsToContents();
    ui->employee_raises_table_view_reassigne->resizeRowsToContents();



    ui->raise_contract_emp_le_reassigne->setText(e->Get_contract_type());

    ui->mod_prom_paiment_emp_le->setText(e->Get_paiment_type());
}

void gestionrh::on_raise_search_name_reassigne_textChanged(const QString &arg1)
{
    ui->raises_table_view_reassigne->setModel(e->employee_list_promotion(arg1));
    ui->raises_table_view_reassigne->resizeRowsToContents();
    ui->raises_table_view_reassigne->resizeColumnsToContents();
}

void gestionrh::on_raises_table_view_reassigne_doubleClicked(const QModelIndex &index)
{
    int row=index.row();
    ui->raise_id_employee_reassigne->setCurrentText( ui->raises_table_view_reassigne->model()->data(ui->raises_table_view_reassigne->model()->index(row,0)).toString());
}

void gestionrh::on_add_raise_to_this_employee_clicked()
{
    QModelIndexList indexes = ui->employee_curret_raises_reassigne->selectionModel()->selection().indexes();
    QModelIndexList indexes2= ui->employee_raises_table_view_reassigne->selectionModel()->selection().indexes();
   if(indexes.count()>0)
   {
       QMessageBox::critical(0,"Hamadi ERP","To add a raise to this employee selection for the Existing raises table",QMessageBox::Ok);
   }
   else if (indexes2.count()>0)
   {
   if(QMessageBox::warning(0,"Hamadi ERP","are you sure you want \n to assigne these raises to this employee ? ","Yes","No")==0)
   {
//       for(int i=0;i<indexes2.count();i++)
//       { if(i%4==0)
//         //int id_raise=indexes2.value();
//       }}
   }
   else
   {
       QMessageBox::information(0,"Hamadi ERP","Assigning request canceled ");
   }
   }
}



void gestionrh::on_search_raise_delete_textChanged(const QString &arg1)
{
    ui->raises_table_view_delete->setModel(r->select_raises(arg1));
    ui->raises_table_view_delete->resizeRowsToContents();
    ui->raises_table_view_delete->resizeColumnsToContents();
}

void gestionrh::on_id_raise_delete_currentTextChanged(const QString &arg1)
{
    r= new raises();
    r->select_raise(arg1.toInt());
    ui->amount_raise_sp_delete->setValue(r->Get_amount());
    ui->Raise_title_le_delete->setText(r->Get_title());
    delete r;
}

void gestionrh::on_raises_table_view_delete_doubleClicked(const QModelIndex &index)
{
    int row=index.row();
    ui->id_raise_delete->setCurrentText( ui->raises_table_view_delete->model()->data(ui->raises_table_view_delete->model()->index(row,0)).toString());
}

void gestionrh::on_delete_search_clear_clicked()
{
    if(QMessageBox::warning(0,"Hamadi ERP","Are you sure you want to delete this raise\n Deleting it will result unassigning employee that has it !","Yes","No")==0)
    {
       if( r->delete_raise(ui->id_raise_delete->currentText().toInt()))
       {
           QMessageBox::information(0,"Hamadi ERP","Raise Delete with success",QMessageBox::Ok);
           update_table_view();
       }
    }
    else
    {
        QMessageBox::information(0,"Hamadi ERP","Raise Delete request canceled",QMessageBox::Ok);

    }
}

void gestionrh::on_update_mod_vacation_clicked()
{
//if()
}

void gestionrh::on_clear_mod_vacation_clicked()
{

}
