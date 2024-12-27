/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import entities.Auto;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import javax.sql.DataSource;

/**
 *
 * @author Jakub Klepacz gr.7
 */

public class AutoDAOJdbc implements AutoDAO {

    private final DataSource ds;

    public AutoDAOJdbc() {
        com.mysql.jdbc.jdbc2.optional.MysqlDataSource mds = new com.mysql.jdbc.jdbc2.optional.MysqlDataSource();
        mds.setUser("root");
        mds.setPort(6033);
        mds.setPassword("");
        mds.setDatabaseName("testdao");
        ds = mds;
    }

    //funkcja getAll
    @Override
    public List<Auto> getAll() {
        
          List<Auto> Lista_aut = new ArrayList<>();
        try (ResultSet rs = ds.getConnection().createStatement().executeQuery("select * from Auta")) {
            while (rs.next()) {
                Auto auto = new Auto();
                auto.setId(rs.getInt("id_auta"));
                auto.setMarka(rs.getString("marka_auta"));
                auto.setModel(rs.getString("model_auta"));
                auto.setRocznik(rs.getInt("rocznik_auta"));
                Lista_aut.add(auto);
            }
        } catch (SQLException ex) {
            System.out.println("getAll: " + ex);
        }
        return Lista_aut;
        
    }

    //funkcja "get"
    @Override
    public Auto get(int id) {
      Auto auto = new Auto();
        try (PreparedStatement pstmt = ds
                .getConnection().prepareStatement("select * from auta where id_auta=?");) {
            pstmt.setInt(1, id);
            ResultSet rs = pstmt.executeQuery();
            rs.next();
            auto.setId(rs.getInt("id_auta"));
            auto.setMarka(rs.getString("marka_auta"));
            auto.setModel(rs.getString("model_auta"));
            auto.setRocznik(rs.getInt("rocznik_auta"));

        } catch (SQLException ex) {
            System.out.println("get " + ex);
        }
        return auto; 
    }

    //funkcja "create"
    @Override
    public void create(Auto auto) {
        try (PreparedStatement pstmt = ds
                .getConnection().prepareStatement("insert into auta(marka_auta,model_auta,rocznik_auta) values(?,?,?)");) {
            pstmt.setString(1, auto.getMarka());
            pstmt.setString(2, auto.getModel());
            pstmt.setInt(3, auto.getRocznik());
            pstmt.executeUpdate();
        } catch (SQLException ex) {
            System.out.println("create " + ex);
        }
    }
    
    // test funkcji "create"
     /* 
        for (int i = 0; i < 23; i++) {
            Auto auto = new Auto("marka_auta_"+i,"model_auta_"+i,(2010+i));
            autoDAO.create(auto);
        }
        List<Auto> Lista_aut = autoDAO.getAll();
        Lista_aut.forEach(System.out::println);
    */
    
    //funkcja "update"
    @Override
    public void update(Auto auto) {
         try (PreparedStatement pstmt = ds
                .getConnection().prepareStatement("update auta set model_auta=? where id_auta = ?");) {
            pstmt.setString(1, auto.getModel());
            pstmt.setInt(2, auto.getId());
            pstmt.executeUpdate();
        } catch (SQLException ex) {
            System.out.println("update " + ex);
        }
         try (PreparedStatement pstmt = ds
                .getConnection().prepareStatement("update auta set marka_auta=? where id_auta = ?");) {
            pstmt.setString(1, auto.getMarka());
            pstmt.setInt(2, auto.getId());
            pstmt.executeUpdate();
        } catch (SQLException ex) {
            System.out.println("update " + ex);
        }
         try (PreparedStatement pstmt = ds
                .getConnection().prepareStatement("update auta set rocznik_auta=? where id_auta = ?");) {
            pstmt.setInt(1, auto.getRocznik());
            pstmt.setInt(2, auto.getId());
            pstmt.executeUpdate();
        } catch (SQLException ex) {
            System.out.println("update " + ex);
        }
    }
    
    // test funkcji "update" 
    /*
    Auto auto = Lista_aut.get(6);
        auto.setModel("nowa_nazwa");
        auto.setRocznik(1234);      
        auto.setMarka("raketa");      
        autoDAO.update(auto);
       Lista_aut.forEach(System.out::println);
    */

    //funkcja "delete"
    @Override
    public void delete(Auto auto) {
         try (PreparedStatement pstmt = ds
                .getConnection().prepareStatement("delete from auta where id_auta= ?");) {
            pstmt.setInt(1, auto.getId());
            pstmt.executeUpdate();
        } catch (SQLException ex) {
            System.out.println("delete " + ex);
        }
    }
    
    //test funkjci "delete"
    /*
     autoDAO.delete(Lista_aut.get(5));
     Lista_aut.forEach(System.out::println);
    */

    //funkcja "clearTable"
    @Override
    public void clearTable() {
         try {
            ds.getConnection().createStatement().executeUpdate("delete from auta");
        } catch (SQLException ex) {
            System.out.println("clear table " + ex);
        }
    }

    //test funkcji "clearTable"
    /*
     autoDAO.clearTable();
     Lista_aut.forEach(System.out::println); 
    */
   

}
